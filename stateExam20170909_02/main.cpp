#include <iostream>

using namespace std;


template <typename T>
struct Node{
    T data;
    Node<T> * next;
    Node() {
        next = nullptr;
    }
};

template <typename T>
class LList {
private:
    Node<T> * start;
    Node<T> * curr;
    Node<T> * end;
    void deleteList(){
        Node<T> * tmp;
        while(start){
            tmp = start;
            start = start->next;
            delete tmp;
        }
        end = nullptr;
    }

    void copyList(const LList & o){
        start = end = nullptr;
        if(o.start){
            Node<T> *tmp = o.start;
            while(tmp){
                insertToEnd(tmp->data);
                tmp = tmp->next;
            }
        }

    }


public:
    LList(){
        start = end = nullptr;
    }

    LList(T data){
        start = end = new Node<T>;
        start->data = data;
    }

    LList(const LList<T> & o){
        copyList(o);
    }


    LList<T>& operator=(const LList<T> & o){
        if(this!=&o){
            deleteList();
            copyList(o);
        }
        return *this;
    }

    void insertToEnd(T data){
        if(!start){
            start = end = new Node<T>;
            start->data = data;
        } else {
            Node<T> *tmp = new Node<T>;
            tmp->data = data;
            tmp->next = nullptr;
            end->next = tmp;
            end = end->next;
        }

    }

    void iterStart(){
        curr = start;
    }

    Node<T> * iter(){
        Node<T> * res = curr;
        if(curr) curr = curr->next;
        return res;
    }

    bool isSorted(){
        Node<T> * tmp = start;
        while(tmp->next){
            if(tmp->data > tmp->next->data) return false;
            tmp = tmp->next;
        }
        return true;
    }

    int lenght(){
        Node<int> * tmp = start;
        int len = 0;
        while(tmp){
            len++;
            tmp = tmp->next;
        }
        return len;
    }

};

LList<int>  mergeLists(LList<LList<int>> l) {
    l.iterStart();
    Node<LList<int>> * tmp = l.iter();
    LList<int> resultList;
    while(tmp){
        if(tmp->data.isSorted()){
            tmp->data.iterStart();
            Node<int> * iter = tmp->data.iter();
            while(iter){
                resultList.insertToEnd(iter->data);
                iter = tmp->data.iter();
            }
        }
        tmp = l.iter();
    }

    for(int i=0; i<resultList.lenght(); ++i){
        resultList.iterStart();
        Node<int> * tmp = resultList.iter();
        while(tmp->next){
            if(tmp->data > tmp->next->data){
                int tmpVal = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = tmpVal;
            }
            tmp = resultList.iter();
        }
    }

    return resultList;
}



int main()
{
    LList<int> l1;
    l1.insertToEnd(2);
    l1.insertToEnd(4);
    l1.insertToEnd(8);
    l1.insertToEnd(11);

    LList<int> l2;
    l2.insertToEnd(4);
    l2.insertToEnd(6);
    l2.insertToEnd(2);
    l2.insertToEnd(3);

    LList<int> l3;
    l3.insertToEnd(1);
    l3.insertToEnd(3);
    l3.insertToEnd(65);

    LList<int> l4;
    l4.insertToEnd(11);
    l4.insertToEnd(12);

    LList<int> l5;
    l5.insertToEnd(9);
    l5.insertToEnd(8);
    l5.insertToEnd(7);

    LList<LList<int>> ll;
    ll.insertToEnd(l1);
    ll.insertToEnd(l2);
    ll.insertToEnd(l3);
    ll.insertToEnd(l4);
    ll.insertToEnd(l5);

    LList<int> res = mergeLists(ll);
    res.iterStart();
    Node<int> * tmp = res.iter();
    while(tmp){
        cout<<tmp->data<<endl;
        tmp = res.iter();
    }


    return 0;
}
