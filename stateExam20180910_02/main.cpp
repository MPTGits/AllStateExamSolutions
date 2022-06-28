#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>

using namespace std;

struct Node {
    int data;
    Node * next;
    Node * skip;
    Node(int d){
        data = d;
        next = skip = nullptr;
    }
};

Node * buildList(const char * fileName){
    int listSize=0;
    int num;
    fstream f;
    f.open(fileName, ios::in);
    if(!f.is_open()){
        cout<<"Error";
        return nullptr;
    }
    Node * dummyNode = new Node(0);
    Node * iter = dummyNode;
    while(f>>num){
        ++listSize;
        Node * newNode = new Node(num);
        iter -> next = newNode;
        iter = iter -> next;
    }

    Node * start = dummyNode->next;

    delete dummyNode;

    int k = ceil(sqrt(listSize));

    Node * currNode = start;
    for(int i = 0; i<listSize/k; ++i){
        if(i+k>listSize) break;
        Node * iteratorNode = currNode;
        int counter = 0;
        while(counter<k){
            iteratorNode = iteratorNode->next;
            ++counter;
        }
        currNode->skip = iteratorNode;
        currNode = iteratorNode;
    }

    return start;
}

void printSequence(Node * n){
    Node * tmp = n;
    while(tmp){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

void printSkipSequence(Node * n){
    Node * tmp = n;
    while(tmp){
        cout<<tmp->data<<" ";
        tmp = tmp->skip;
    }
    cout<<endl;
}
//5 6 30 40 50 60 100 200 4313
bool member(Node * n, int x){
    Node * tmp = n;
    if(x<tmp->data) return false;
    while(tmp){
        cout<<tmp->data<<"->";
        if(tmp->data == x) return true;

        if(!tmp->skip || (tmp->data < x && tmp->skip->data > x)){
            tmp = tmp->next;
        } else {
            if(tmp->data>x && tmp->skip->data>x) return false;
            tmp = tmp->skip;
        }
    }
    return false;

}




int main()
{


    fstream f;
    f.open("test.txt", ios::in);
    char a[100], b[100] ,c[100];
    while(f>>a>>b>>c) cout<<a<<" "<<b<<" "<<c<<endl;
    for(int i =0; i<strlen(c); ++i)
        cout<<c[i];

    return 0;
}
