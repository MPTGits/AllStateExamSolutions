#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

struct Node{
    string text;
    Node* next;

    Node(string val){
        text = val;
        next = nullptr;
    }
};

void sortLex(vector<string>& chains){
    for(int i =0;i<chains.size(); ++i){
        for(int j = i+1; j<chains.size(); ++j){
            if(chains[i]>chains[j]){
                string tmp = chains[i];
                chains[i] = chains[j];
                chains[j] = tmp;
            }
        }
    }

}


void unite(Node * l){
    if(!l) return;
    Node * iter = l->next;
    vector<string> currResult;
    bool useNextValue = true;
    while(iter != l){
        if(useNextValue) currResult.push_back(iter->text);
        if(iter->text.back() == iter->next->text[0]){
            string tmp = currResult.back();
            currResult.pop_back();
            tmp = tmp + "-" + iter->next->text;
            currResult.push_back(tmp);
            iter = iter->next;
            useNextValue = false;
            continue;
        } else {
            useNextValue = true;
            iter = iter->next;
        }
    }


    if(iter->text.back() == iter->next->text[0]){
        currResult[0] = currResult.back() + "-" + currResult[0];
        currResult.pop_back();
    }

    sortLex(currResult);

    for(int i =0; i<currResult.size(); ++i){
        cout<<currResult[i]<<endl;
    }

}


int main()
{
    Node n1("street");
    Node n2("taxi");
    Node n3("ink");
    Node n4("dog");
    Node n5("smile");
    Node n6("eat");
    Node n7("tall");
    Node n8("pass");

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    n8.next = &n1;

    unite(&n1);

    return 0;
}
