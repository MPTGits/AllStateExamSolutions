#include <iostream>

using namespace std;



void findPath(vector<vector<pair<int, char>>> t,int v, bool * visited, vector<vector<pair<int,char>>>& paths){
    if(visited[v] == true) return;
    if(t[v].empty()){
    }


}


void commonBranch(vector<vector<pair<int, char>>> t, int v, int u, int k){
    bool visited = new bool[t.size()];
    vector<vector<pair<int, char>>> pathU;
    vector<vector<pair<int, char>>> pathV;

    findPath(t, u, visited, pathU);
    findPath(t, v, visited, pathV);


    findPath(u, visited,)





    delete[] visited;
}

//Actually this is same as last, our tutor solved it the same as me in the stateExam20190910_02 but had a struct Tree that had only a node as element
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
