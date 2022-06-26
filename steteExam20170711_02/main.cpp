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

    void iterStart() {
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

void sortList(LList<int> & l){
    Node<int> * tmp;

    for(int i = 0; i<l.lenght(); ++i){
        l.iterStart();
        tmp = l.iter();
        while(tmp->next){
            if(tmp->data > tmp->next->data){
                int tmpVal = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = tmpVal;
            }
            tmp = l.iter();
        }
    }

}


int main()
{
    LList<int> l;

    l.insertToEnd(5);
    l.insertToEnd(4);
    l.insertToEnd(3);
    l.insertToEnd(2);
    l.insertToEnd(1);

    sortList(l);

    l.iterStart();
    Node<int> * tmp = l.iter();
    while(tmp){
        cout<<tmp->data<<endl;
        tmp = tmp->next;
    }

    return 0;
}
