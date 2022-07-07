#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>

using namespace std;

struct Node {
    char text;
    Node *left, *right;
    Node(char v){
        text = v;
        left = right =nullptr;
    }

};

int treeHeight(Node * tree){
    if(!tree) return 0;
    return 1 + max(treeHeight(tree->left), treeHeight(tree->right));
}


void print(Node * root){
    if(!root) return;
    int treeSize = treeHeight(root) - 1;
    queue<Node *> q;
    vector<string> res;
    string currWord;
    q.push(root);
    int lvl = 0;
    int counter = 0;
    while(!q.empty()){
        ++counter;
        Node * val = q.front();
        q.pop();
        if(!val){
            currWord += " ";
            q.push(nullptr);
            q.push(nullptr);
        }
        else{
            currWord += val->text;
            q.push(val->left);
            q.push(val->right);
        }
        if(counter == pow(2, lvl)){
            counter = 0;
            lvl++;
            if(lvl>treeSize){
                int end = currWord.length()-1;
                while(currWord[end] == ' '){
                    end--;
                }
                cout<<currWord.substr(0, end+1);
                break;
            }

            cout<<currWord<<endl;
            currWord = "";
        }
    }
}

int main()
{
    Node n1('I');
    Node n2('a');
    Node n3('m');
    Node n4('g');
    Node n5('o');
    Node n6('o');
    Node n7('d');
    Node n8('a');
    Node n9('t');
    Node n10('s');
    Node n11('o');
    Node n12('l');
    Node n13('v');
    Node n14('i');
    Node n15('n');
    Node n16('g');
    Node n17('p');
    Node n18('r');
    Node n19('o');
    Node n20('b');
    Node n21('l');
    Node n22('e');
    Node n23('m');
    Node n24('s');
    Node n25('!');


    n1.left = &n2;
    n1.right = &n3;

    n2.left = &n4;
    n2.right = &n5;

    n3.left = &n6;
    n3.right = &n7;

    n4.left = &n8;
    n4.right = &n9;

    n5.right = &n10;

    n6.left = &n11;
    n6.right = &n12;

    n7.left = &n13;
    n7.right = &n14;

    n8.left = &n15;
    n8.right = &n16;

    n9.right = &n17;

    n10.left = &n18;
    n10.right = &n19;

    n11.left = &n20;
    n11.right = &n21;

    n12.left = &n22;
    n12.right = &n23;

    n15.left = &n24;

    n16.right = &n25;

    print(&n1);

    return 0;
}
