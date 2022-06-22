#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node{
    T val;
    Node * link;
    Node(T v){
        val = v;
        link = nullptr;
    };
};

int main()
{
    Node<int> node1(1);
    Node<int> node2(2);
    Node<int> node3(3);
    Node<int> node4(4);
    Node<int> * first = &node1;
    Node<int> * second = &node2;
    Node<int> * third = &node3;
    Node<int> * forth = &node2;
    first->link = second;
    second->link = third;
    third->link = forth;

    unordered_set<Node<int>*> s;

    Node<int> * tmp = first;
    while(tmp){
        if(s.find(tmp) != s.end()){
            cout<<"Cycle";
            return 0;
        }
        else{
            s.insert(tmp);
        }
        tmp = tmp->link;
    }




    return 0;
}
