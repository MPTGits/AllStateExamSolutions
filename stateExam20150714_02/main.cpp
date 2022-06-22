#include <iostream>

using namespace std;


//Actually this solution dose not work good for the filterOdd function so make the struct a class and add a destructor so we can tear down nodes inside of filterOdd
//Since the task was stated to have a inductive reccursive definition of a binary tree we will need to go ahead with this approach ;(
struct Node{
    int data;
    int numAdj;
    Node ** adj;
};

bool member(Node * root ,int m){
    if(!root) return false;
    if(root->data == m) return true;
    bool isFound;
    for(int i=0; i<root->numAdj; ++i){
        isFound = member(root->adj[i], m);
        if(isFound) return true;
    }
    return false;

}

void deleteTree(Node *& root){
    if(!root) return;
    if(root->numAdj == 0){
        delete root;
        root = nullptr;
        return;
    }
    for(int i=0; i<root->numAdj; ++i){
        deleteTree(root->adj[i]);
    }

    root = nullptr;
}

void filterOdd(Node *& root){
    if(!root) return;
    if(root->data % 2 != 0){
        deleteTree(root);
        return;
    }
    for(int i=0; i<root->numAdj; ++i){
        filterOdd(root->adj[i]);
    }

}


void printTree(Node * root){
    if(!root) return;
    cout<<root->data<<" ";
    for(int i=0; i<root->numAdj; ++i){
        printTree(root->adj[i]);
    }
    cout<<endl;
}


int main()
{

    /*
    Node n6;
    n6.data = 6;
    n6.numAdj = 0;
    n6.adj = nullptr;
    Node n5;
    n5.data = 5;
    n5.numAdj = 0;
    n5.adj = nullptr;
    Node n4;
    n4.data = 4;
    n4.numAdj = 0;
    n4.adj = nullptr;
    Node n3;
    n3.data = 3;
    n3.numAdj = 3;
    Node * arr1[3] = {&n4, &n5, &n6};
    n3.adj = arr1;
    Node n2;
    n2.data = 2;
    n2.numAdj = 0;
    n2.adj = nullptr;
    Node n1;
    Node * arr2[2] = {&n2, &n3};
    n1.data = 8;
    n1.numAdj = 2;
    n1.adj = arr2;
    */
    Node * n6 = new Node;
    n6->data = 6;
    n6->numAdj = 0;
    n6->adj = nullptr;
    Node * n5 = new Node;
    n5->data = 5;
    n5->numAdj = 0;
    n5->adj = nullptr;
    Node * n4 = new Node;
    n4->data = 4;
    n4->numAdj = 0;
    n4->adj = nullptr;
    Node * n3 = new Node;
    n3->data = 3;
    n3->numAdj = 3;
    Node * arr1[3] = {n4, n5, n6};
    n3->adj = arr1;
    Node * n2 = new Node;
    n2->data = 2;
    n2->numAdj = 0;
    n2->adj = nullptr;
    Node * n1 = new Node;
    Node * arr2[2] = {n2, n3};
    n1->data = 8;
    n1->numAdj = 2;
    n1->adj = arr2;



    Node * t = n1;
    cout << member(n1, 1) << endl;
    printTree(n1);
    filterOdd(t);
    printTree(n1);


    return 0;
}
