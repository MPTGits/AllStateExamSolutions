#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    int d;
    Node * left;
    Node * right;

    Node(int data){
        d = data;
        left = right = nullptr;
    }

};

Node * buildTree(fstream & fs){
    int num;
    char c;
    fs>>c;
    if(fs.peek() == ')'){
        fs>>c;
        return nullptr;
    }
    fs>>num;
    Node * data = new Node(num);
    fs>>c;
    data->left = buildTree(fs);
    fs>>c;
    data->right = buildTree(fs);
    fs>>c;

    return data;
}

void printTree(Node * root){
    if(!root) return;
    cout<<root->d<<" ";
    printTree(root->left);
    printTree(root->right);

}


int main()
{
    fstream f;
    f.open("testFile.txt", ios::in);

    Node * res = buildTree(f);

    printTree(res);

    return 0;
}
