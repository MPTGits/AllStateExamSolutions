#include <iostream>

using namespace std;


struct Node{
    Node * next;
    int data;
};


Node * preceeds(Node * l, int m, int n){
    Node * tmp = l;
    while(l){
        if(l->data == m && l->next && l->next->data == n) return l;
        l = l->next;
    }
    return nullptr;
}

//Вкарва новият връх и връща указател към него
Node * insertAfter(Node * l, int data){
    Node * add = new Node;
    add->data = data;
    Node * tmp = l->next;
    l->next = add;
    add->next = tmp;
    return add;
}

Node * mergeLists(Node * l1, Node * l2, int n, int m){
    Node * l1StartPoint = preceeds(l1, n , m);
    Node * l2StartPoint = preceeds(l2, m, n)->next;
    Node * iter = l2StartPoint->next;
    Node * tmp = l1StartPoint;
    while(iter->next->data != l2StartPoint->data){
        tmp = insertAfter(tmp, iter->data);

        iter = iter->next;
    }

    return l1;
}



int main()
{
    Node * n1 = new Node;
    Node * n2 = new Node;
    Node * n3 = new Node;
    Node * n4 = new Node;
    n1->data = 1;
    n1->next = n2;
    n2->data = 2;
    n2->next = n3;
    n3->data = 3;
    n3->next = n4;
    n4->data = 4;
    n4->next = n1;
    Node * x1 = new Node;
    Node * x2 = new Node;
    Node * x3 = new Node;
    Node * x4 = new Node;
    x1->data = 8;
    x1->next = x2;
    x2->data = 3;
    x2->next = x3;
    x3->data = 2;
    x3->next = x4;
    x4->data = 9;
    x4->next = x1;
    Node * res = preceeds(n1, 2, 3);
    Node* res2 = mergeLists(n1, x1, 2, 3);

    Node * tmp1 = n1->next;
    cout<<n1->data<<" ";
    while(tmp1 != n1){
        cout<<tmp1->data<<" ";
        tmp1 = tmp1->next;
    }

    cout<<endl;

    Node * tmp2 = res2->next;
    cout<<res2->data<<" ";
    while(tmp2 != res2){
        cout<<tmp2->data<<" ";
        tmp2 = tmp2->next;
    }
    return 0;
}
