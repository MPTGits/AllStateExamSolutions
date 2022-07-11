#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

struct Node {
    int data;
    vector<Node *> children;

    Node(int d){
        data = d;
    }
};

struct TreeSeq{
    vector<pair<int, int>> seq;

    int length() const{
        return seq.size();
    }
};

bool validateSequence(const TreeSeq& s){
    int numRoots = 0;
    vector<pair<int, int>> seq = s.seq;
    int currHighestLvl = 0;
    for(int i=0; i<seq.size(); ++i){
        if(seq[i].first == 0){
            numRoots++;
        }
        if(numRoots>1) return false;
        if(seq[i].first > currHighestLvl){
            if(seq[i].first - currHighestLvl <= 1) currHighestLvl = seq[i].first;
            else return false;
        }
    }

    return numRoots == 0? false:true;

}

Node * treeGenerator(const TreeSeq& s, int currElIdx){
   unordered_map<int, Node*> m;


   Node * root = new Node(s.seq[0].second);
   m[0] = root;

   for(int i = 1; i < s.length(); ++i){
    int currLvl = s.seq[i].first;
    Node * tmp = new Node(s.seq[i].second);
    m[currLvl - 1]->children.push_back(tmp);
    m[currLvl] = tmp;
   }

    return root;
}


Node * buildTree(const TreeSeq s){
    if(!validateSequence(s)) return nullptr;
    Node * resultTree = treeGenerator(s, 0);
}


void printTree(Node * t){
    cout<<t->data<<" ";
    if(t->children.empty()){
        return;
    }

    for(int i = 0; i<t->children.size(); ++i){
     printTree(t->children[i]);
    }

    cout<<endl;
}


int main()
{
    TreeSeq ts;
    ts.seq.push_back(make_pair(0, 5));
    ts.seq.push_back(make_pair(1, 4));
    ts.seq.push_back(make_pair(1, 5));
    ts.seq.push_back(make_pair(2, 3));
    ts.seq.push_back(make_pair(1, 6));
    ts.seq.push_back(make_pair(2, 2));
    ts.seq.push_back(make_pair(3, 3));
    ts.seq.push_back(make_pair(2, 5));

    Node * res = buildTree(ts);

    printTree(res);

    return 0;
}
