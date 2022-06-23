#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    vector<Node *> children;
};

Node * buildTree(int * arr, int start, int end, int k){
    if(!arr || start>=end) return nullptr;
    Node * tmp = new Node;
    tmp->data = arr[start];
    for(int i=(start*k)+1; i<(start*k)+1+k; ++i){
        if(i>=end) break;
        Node * childNode = buildTree(arr, i, end, k);
        if(childNode){
            tmp->children.push_back(childNode);
        }
    }
    return tmp;
}


int depth(Node * t){
    if(!t || t->children.empty()){
        return 0;
    }
    int currMax = 0, curr;
    for(int i=0; i<t->children.size(); ++i){
        curr = 1 + depth(t->children[i]);
        if(curr>currMax) currMax = curr;
    }
    return currMax;
}

void printTree(Node *t) {
    if(!t) return;
    cout<<t->data<<endl;
    for(int i=0; i<t->children.size(); ++i){
        cout<<t->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0; i<t->children.size(); ++i){
        printTree(t->children[i]);
    }
}



int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8 ,9 , 10};
    Node * t = buildTree(arr, 0, 10, 3);
    printTree(t);
    cout<<depth(t)<<endl;
    return 0;
}
