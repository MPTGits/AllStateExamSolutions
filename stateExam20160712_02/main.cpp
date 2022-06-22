#include <iostream>
#include <fstream>>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>


using namespace std;

struct Node{
    int data;
    vector<Node*> adj;
    Node(int a=99){
        data = a;
    }
};

void printTree(Node * root){
    queue<Node *> q;
    q.push(root);
    int lvl = 0;
    while(!q.empty()){
        Node * tmp = q.front();
        q.pop();
        cout<<tmp->data<<" "<<tmp->adj.size()<<endl;
        for(int i=0; i<tmp->adj.size(); ++i){
            q.push(tmp->adj[i]);
        }
    }

}

void higestSum(Node * root, int & currHigest, vector<int> &path){
    if(root->adj.empty()){
        int sum = 0;
        for(int i=0;i<path.size();++i){
            sum += path[i];
        }
        sum += root->data;
        if(sum>currHigest) currHigest = sum;
    }
    path.push_back(root->data);
    for(int i =0; i<root->adj.size(); ++i){
        if(find(path.begin(), path.end(), root->adj[i]->data) == path.end()){
            higestSum(root->adj[i], currHigest, path);
        }
    }
    path.pop_back();

}


void maxDeptSum(const char * fileName){
    fstream f(fileName);
    char c;
    f.get(c);
    while(!(c >= '0' && c<='9')){
        f.get(c);
    }
    Node * root;
    vector<char> numVec;
    while(c >= '0' && c<='9'){
        numVec.push_back(c);
        f.get(c);
    }
    int num = 0;
    int enlarger = 1;
    for(int i=numVec.size()-1; i>=0; --i){
        num += enlarger*numVec[i]-'0';
        enlarger *= 10;
    }
    root->data = num;
    cout<<num<<endl<<endl;
    stack<Node *> s;

    while(f.get(c)){
        if(c=='('){
            if(f.peek() >= '0' && f.peek()<= '9'){
                vector<char> numVec;
                while(f.peek() >= '0' && f.peek()<= '9'){
                    f.get(c);
                    numVec.push_back(c);
                }
                int num = 0;
                int enlarger = 1;
                for(int i=numVec.size()-1; i>=0; --i){
                    num += enlarger*(numVec[i]-'0');
                    enlarger *= 10;
                }
                Node * newNode = new Node(num);
                root->adj.push_back(newNode);
                s.push(root);
                root = newNode;
           }
           else if(f.peek() == ')'){
                //root = s.top();
                //s.pop();
                f.get(c);
           }
        }
        else if(c==')'){
            if(s.empty()){
                break;
            }
            root = s.top();
            s.pop();
        }
    }
    printTree(root);
    int currHighest = 0;
    vector<int> path;
    higestSum(root, currHighest, path);
    cout<<"Highest sum is:"<<currHighest;

}


int main()
{
    maxDeptSum("test.txt");
    return 0;
}
