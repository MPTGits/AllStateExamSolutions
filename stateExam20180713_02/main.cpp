#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Tree{
    char data;
    vector<Tree *> children;
    Tree(char d): data(d){};
};

int treeMaxDepth(Tree * t){
    if(!t) return 0;
    if(t->children.empty()) return 1;

    int maxDepth = 0;
    int depth;
    for(int i =0; i<t->children.size(); ++i){
        depth = treeMaxDepth(t->children[i]);
        if(depth>maxDepth) maxDepth = depth;
    }

    return 1 + maxDepth;
}


void readLastHelper(Tree * t, vector<Tree *> & visited, int currDepth,int treeMaxDepthVal){
    if(!t) return;
    if(find(visited.begin(), visited.end(), t) != visited.end()) return;
    if(t->children.empty() && currDepth == treeMaxDepthVal){
        cout<<t->data;
        return;
    }
    visited.push_back(t);
    for(int i =0; i<t->children.size(); ++i){
        readLastHelper(t->children[i], visited, currDepth+1, treeMaxDepthVal);
    }
    visited.pop_back();
}

void readLast(Tree * t){
    vector<Tree *> visited;
    int treeMaxDepthVal = treeMaxDepth(t);
    readLastHelper(t, visited, 1,treeMaxDepthVal);
}

void serializeHelper(Tree * t, fstream& f){
    if(!t){
        f<<"*";
        return;
    }

    f<<"("<<t->data<<" ";

    for(int i =0; i<t->children.size(); ++i){
        serializeHelper(t->children[i], f);
    }
    if(t->children.size() < 3){
        for(int i = 0; i<(3-t->children.size()); ++i)
            f<<" *";
    }

    f<<")";

}


void serialize(Tree * t, const char * fileName){
    fstream f;
    f.open(fileName, ios::out);
    serializeHelper(t, f);
}


int main()
{
    Tree t0('b');
    Tree t1('x');
    Tree t2('y');
    Tree t3('p');
    Tree t4('q');
    Tree t5('r');
    Tree t6('c');
    Tree t7('a');
    Tree t8('s');
    Tree t9('t');

    t0.children.push_back(&t1);
    t0.children.push_back(&t2);

    t1.children.push_back(&t3);
    t1.children.push_back(&t4);
    t1.children.push_back(&t5);

    t5.children.push_back(&t6);
    t5.children.push_back(&t7);

    t2.children.push_back(&t8);

    t8.children.push_back(&t9);

    readLast(&t0);
    cout<<endl;
    serialize(&t0, "testFile.txt");

    return 0;
}
