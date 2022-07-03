#include <iostream>
#include <vector>


using namespace std;

struct Node{
    int value;
    char lable;
    vector<Node *> children;

    Node(int v, char l):value(v), lable(l){};

};

void findPath(Node * u, vector<Node *> visited, vector<vector<Node *>> &paths){
    if(!u) return;
    visited.push_back(u);
    if(u->children.empty()){
        paths.push_back(visited);
        return;
    }
    for(int i =0; i<u->children.size(); ++i){
        findPath(u->children[i], visited, paths);
    }
    visited.pop_back();

}

void printPaths(vector<vector<Node *>> v){
    for(int i =0;i<v.size(); ++i){
        for(int j =0;j<v[i].size(); ++j){
            cout<<v[i][j]->lable<<" ";
        }
        cout<<endl;
    }

}

void commonBranches(Node * t, Node * u, Node * v, int k){
    vector<vector<Node*>> pathsU;
    vector<vector<Node *>> pathsV;

    vector<Node *> visited;

    findPath(u, visited, pathsU);
    findPath(v, visited, pathsV);

    printPaths(pathsU);
    cout<<endl;
    printPaths(pathsV);
    cout<<endl;

    for(int i = 0; i < pathsU.size(); ++i){
        for(int j = 0; j < pathsV.size(); ++j){
            if(pathsU[i].size() != pathsV[j].size()) continue;
            char * word = new char[pathsU.size()];
            bool noMatch = false;
            int score = 0;
            for(int k = 0; k<pathsU[i].size(); ++k){
                if(pathsU[i][k]->lable != pathsV[j][k]->lable){
                        noMatch = true;
                        break;
                }
                word[k] = pathsU[i][k]->lable;
                score += pathsU[i][k]->value + pathsV[j][k]->value;

            }

            if(!noMatch && score == k){
                cout<<word<<" ";
            }

            delete[] word;
        }
    }



}

//The task is wrong it dose not cover the label and the value to be on the edges and not on the vertecies
int main()
{
    Node n1(2, 'a');
    Node n2(4, 'f');
    Node n3(4, 'b');
    Node n4(8, 'c');
    Node n5(2, 'h');
    Node n6(3, 'f');
    Node n7(5, 'b');
    Node n8(5, 'c');
    Node n9(5, 'f');


    n1.children.push_back(&n2);
    n1.children.push_back(&n7);

    n7.children.push_back(&n8);

    n8.children.push_back(&n9);

    n2.children.push_back(&n3);

    n3.children.push_back(&n4);

    n4.children.push_back(&n5);
    n4.children.push_back(&n6);

    commonBranches(&n1, &n7, &n3, 30);
    return 0;
}
