#include <iostream>

using namespace std;


template<typename T=int>
struct Node{
    T data;
    Node<T> * left;
    Node<T> * right;
    Node(T val){
        data = val;
        left = right = nullptr;
    }

};

int getHeight(Node<> * tree){
    return tree? 1+max(getHeight(tree->left), getHeight(tree->right)): 0;
}

bool isTreeBalanced(Node<> * tree){
    cout<<abs(getHeight(tree->left) - getHeight(tree->right))<<endl;
    return abs(getHeight(tree->left) - getHeight(tree->right)) <= 1;
}


int main()
{
    Node<> tree1(1);
    Node<> tree2(1);
    Node<> tree3(1);
    Node<> tree4(1);
    Node<> tree5(1);
    Node<> tree6(1);
    Node<> tree7(1);

    tree1.left = &tree2;
    tree1.right = &tree3;

    tree2.left=&tree4;
    tree2.right=&tree5;

    tree4.left = &tree6;

    cout<<isTreeBalanced(&tree1);
    return 0;
}
