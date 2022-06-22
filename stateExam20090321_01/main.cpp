#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


struct Node {
    char val;
    bool isInitilized = false;
};


void DFS(int currVertex, Node ** graphMatrix, int matrixSize, bool * visited, vector<char> & word, bool * reachable){
    reachable[currVertex] = true;
    for(int i =0; i<matrixSize;++i){
        if(graphMatrix[currVertex][i].isInitilized && !visited[i]){
            bool not_do = false;
            for(int j =0; j<word.size(); ++j){
                if(graphMatrix[currVertex][i].val == word[j]){
                    not_do = true;
                }
            }
        if(!not_do){
            word.push_back(graphMatrix[currVertex][i].val);
            visited[i] = true;
            DFS(i, graphMatrix, matrixSize, visited, word, reachable);
        }
        }
    }
    visited[currVertex] = false;
    word.pop_back();
}



int main()
{
    char graphFileLine[10];
    fstream graphFile("graphFile.txt");
    graphFile.getline(graphFileLine, 4);
    int numNodes = graphFileLine[0] - '0', numEdges = graphFileLine[2] - '0';
    if(numEdges > (numNodes*(numNodes-1))/2){
        cout<<"Invalid graph(assume graph is not multi graph"<<endl;
        return 0;
    }
    Node ** graphMatrix = new Node*[numNodes];
    for(int row =0; row<numNodes; ++row)
        graphMatrix[row] = new Node[numNodes];
    while(graphFile.getline(graphFileLine, 7)){
        graphMatrix[graphFileLine[0]-'0'][graphFileLine[2] - '0'].val = graphFileLine[4];
        graphMatrix[graphFileLine[0]-'0'][graphFileLine[2] - '0'].isInitilized = true;
    }

    int startVertex;
    cout<<"Input start vertex:";
    cin>>startVertex;
    bool * visited = new bool[numNodes];
    bool * reachable = new bool[numNodes];
    for(int i=0; i<numNodes;++i){
        visited[i] = false;
        reachable[i] = false;
    }
    vector<char> word;
    DFS(startVertex, graphMatrix, numNodes, visited, word,reachable);

    for(int i=0; i<numNodes; ++i){
        cout<<i<<": "<<reachable[i]<<endl;
    }

    for(int row =0; row<numNodes; ++row)
        delete[] graphMatrix[row];
    delete[] graphMatrix;
    delete[] visited;
    delete[] reachable;

    return 0;
}
