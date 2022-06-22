#include <iostream>
#include <unordered_set>

using namespace std;

struct Node{
    int data;
    Node * next;
    Node * prev;
};

bool member(Node * l, int m){
    Node * memberEl = nullptr;
    while(l){
        if(l->data == m) memberEl = l;
        l=l->next;
    }
    return memberEl != nullptr;
}

int distanceFromEnds(Node * l, bool distanceFromLeftEnd){
    int size = 0;
    Node * tmp = distanceFromLeftEnd? l->prev: l->next;
    while(tmp){
        ++size;
        if(distanceFromLeftEnd){
            tmp = tmp->prev;
        } else{
            tmp = tmp->next;
        }
    }
    return size;
}

int listLen(Node * l){
    int size = 0;
    while(l){
        size++;
        l=l->next;
    }
    return size;
}

Node * copyList(Node * l, bool returnPointerToEnd){
    Node * resNode1 = new Node;
    resNode1->data = l->data;
    resNode1->next=resNode1->prev = nullptr;
    Node * tmp = l->next;

    while(tmp){
        Node * newResNode = new Node;
        newResNode->data = tmp->data;
        newResNode->prev = resNode1;
        newResNode->next = nullptr;
        resNode1->next = newResNode;
        resNode1 = newResNode;
        tmp = tmp->next;
    }
    if(!returnPointerToEnd){
        while(resNode1->prev) resNode1 = resNode1->prev;
    }
    return resNode1;

}


Node * join(Node * l1, Node * l2){
    if(!l1 || !l2) return nullptr;
    Node * resL1 = copyList(l1, true);
    Node * resL2 = copyList(l2, false);

    Node * tmpL1 = resL1;
    Node * tmpL2 = resL2;

    Node * endL1 = resL1;

    while(tmpL1 && tmpL2){
        if(tmpL1->data == tmpL2->data ){
            endL1->next = tmpL2;
            resL2->prev = tmpL1;
            while(resL1->prev) resL1 = resL1->prev;
            return resL1;
        }
        tmpL1 = tmpL1->prev;
        tmpL2 = tmpL2->next;
    }
    return nullptr;
}

bool isJoin(Node * start, bool movementForward){
    if(!start) return false;
    if(movementForward){
        while(start->next){
            if(start->next->prev != start)
                return true;
            start = start->next;
        }
        return false;
    } else {
        while(start->prev){
            if(start->prev->next != start)
                return true;
            start = start->prev;
        }
        return false;
    }
}

bool isJoined(Node * start, Node * end){
   return isJoin(start, true) && isJoin(end, false);
};

int sum(Node * start){
    int sum = 0;
    Node * crossingPoint;
    if(!start) return sum;
    while(start){
        if(start->next && start->next->prev != start)
            crossingPoint = start->next->prev;
        sum += start->data;
        start = start->next;
    }


    while(crossingPoint->prev->next == crossingPoint){
        sum += crossingPoint->data;
        crossingPoint = crossingPoint->prev;
    }

    return sum + crossingPoint->data;

}


/*
Node * join(Node * l1, Node * l2, int m){
    if(!l1 || !l2) return nullptr;
    Node * memberNode1 = member(l1, m);
    Node * memberNode2 = member(l2, m);
    if(!memberNode1 || !memberNode2) return nullptr;
    int distanceFromEnd = distanceFromEnds(memberNode1, false);
    int distanceFromBeg = distanceFromEnds(memberNode2, true);
    if(distanceFromEnd != distanceFromBeg) return nullptr;
    Node * resNode2 = new Node;
    resNode2->data = l2->data;
    resNode2->next = resNode2->prev = nullptr;
    Node * resNode1 = new Node;
    resNode1->data = l1->data;
    resNode1->next = resNode1->prev = nullptr;

    int list1Size = listLen(l1);
    int list2Size = listLen(l2);


    Node * tmp = l1->next;
    int counter = list1Size - distanceFromEnd;
    while(tmp){
        Node * newResNode = new Node;
        newResNode->data = tmp->data;
        newResNode->prev = resNode1;
        newResNode->next = nullptr;
        resNode1->next = newResNode;
        resNode1 = newResNode;
        if(counter-1 == 0){
            resNode2->prev = newResNode;
        }
        tmp = tmp->next;
        --counter;
    }

    tmp = l2->next;
    counter = list2Size - distanceFromEnd;
    while(tmp){
        Node * newResNode = new Node;
        newResNode->data = tmp->data;
        newResNode->prev = resNode2;
        newResNode->next = nullptr;
        resNode2->next = newResNode;
        resNode2 = newResNode;
        if(counter == 0){
            resNode1->next = newResNode;
        }
        tmp=tmp->next;
        --counter;
    }
    //Iterating back to the beggining
    while(resNode1->prev != nullptr)
        resNode1 = resNode1->prev;
    return resNode1;
}

bool isJoined(Node * l1, Node * l2){
    unordered_set<Node *> s1;
    unordered_set<Node *> s2;
    Node * start = l1;
    Node * end = l2;

    while(l1->next){
        s1.insert(l1);
        l1 = l1->next;
    }

    while(l2->prev){
        s2.insert(l2);
        l2 = l2->prev;
    }

    int nonMatchingL1 =0, nonMatchingL2=0;

    l1 = start;
    l2 = end;

    while(l1){
        if(s2.find(l1) == s2.end()){
            cout<<"In";
            nonMatchingL1++;
        }
        l1 = l1->next;
    }

    while(l2){
        if(s1.find(l2) == s1.end()){
            cout<<"In"<<endl;
            nonMatchingL2++;
        }
        l2 = l2->prev;
    }

    return nonMatchingL1 != listLen(start) && nonMatchingL2 != listLen(end) && listLen(start)-nonMatchingL1 == listLen(end) - nonMatchingL2;
}
*/


int main()
{
    Node n1;
    n1.data = 1;
    Node n2;
    n2.data = 3;
    Node n3;
    n3.data = 5;
    Node n4;
    n4.data = 7;
    Node n5;
    n5.data = 9;
    Node n6;
    n6.data = 6;

    n1.next = &n2;
    n1.prev = nullptr;

    n2.next = &n3;
    n2.prev = &n1;

    n3.next = &n4;
    n3.prev = &n2;

    n4.next = &n5;
    n4.prev = &n3;

    n5.next = &n6;
    n5.prev = &n4;

    n6.next = nullptr;
    n6.prev = &n5;


    Node x1;
    x1.data = 3;
    Node x2;
    x2.data = 4;
    Node x3;
    x3.data = 8;
    Node x4;
    x4.data = 5;
    Node x5;
    x5.data = 7;


    x1.next = &x2;
    x1.prev = nullptr;

    x2.next = &x3;
    x2.prev = &x1;

    x3.next = &x4;
    x3.prev = &x2;

    x4.next = &x5;
    x4.prev = &x3;

    x5.next = nullptr;
    x5.prev = &x4;


    Node * res = join(&n1, &x1);

    Node * tmp = res;
    while(tmp->next) tmp = tmp->next;

    cout<<isJoined(res, tmp)<<endl<<endl;
    cout<<isJoined(&x1, &x5)<<endl<<endl;
    cout<<"Sum: "<<sum(res)<<endl;

    while(res){
        cout<<res->data<<endl;
        res = res->next;
    }


    return 0;
}
