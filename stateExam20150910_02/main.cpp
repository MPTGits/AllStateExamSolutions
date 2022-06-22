#include <iostream>

using namespace std;

class Graph{
private:
    int v[1000];
    int numVertexes;
    bool ** e;
    int numEdges;

    void copyData(const Graph & o){
        numVertexes = o.numVertexes;
        numEdges = o.numEdges;
        for(int i = 0; i<numVertexes; ++i)
            v[i] = o.v[i];
        e = new bool*[numVertexes];
        for(int i=0; i<numVertexes; ++i)
            e[i] = new bool[numVertexes];
    }

    void deleteData(){
        for(int i=0; i<numVertexes; ++i)
            delete[] e[i];
        delete[] e;
    }

    bool isVertex(int i){
        return i<numVertexes && i>=0;
    }

        bool hasPath(int x, int y, bool * visited){
        visited[x] = true;
        if(!isVertex(x) || !isVertex(y)) throw "Provided node is not a vertex";
        if(x == y) return true;
        for(int i=0; i<numVertexes; ++i){
            if(e[x][i] && !visited[i]){
                if(isPath(i, y)) return true;
            }
        }
        return false;
    }

public:
    Graph(){
        numVertexes = numEdges = 0;
    }

    Graph(int vertexes, int ** edges, int numEdges){
        if(numVertexes>1000) throw "Too many vertexes";
        numVertexes = vertexes;
        numEdges = numEdges;
        for(int i = 0; i<numVertexes; ++i)
            v[i] = i;
        e = new bool*[numVertexes];
        for(int i=0; i<numVertexes; ++i)
            e[i] = new bool[numVertexes];

         for(int i=0; i<numVertexes; ++i)
            for(int j=0; j<numVertexes; ++j)
                e[i][j] = 0;
        for(int i=0; i<numEdges; ++i) {
            if(!isVertex(edges[i][0]) || !isVertex(edges[i][0]))
                throw "There is an invalid edge in the list of edges provided";
            e[edges[i][0]][edges[i][1]] = 1;
        }
    }

    Graph(const Graph & o){
        copyData(o);
    }

    Graph& operator=(const Graph & o){
        if(this!=&o){
            deleteData();
            copyData(o);
        }
        return *this;
    }

    ~Graph() {
        deleteData();
    }


    int getNodeValue(int x){
        if(!isVertex(x)) throw "Provided node is not a vertex";
        return v[x];
    }

    int getNumVertexes() const{
        return numVertexes;
    }

    bool isPath(int x, int y) {
        bool * visited = new bool[numVertexes];
        for(int i=0; i<numVertexes; ++i)
            visited[i] = false;
        bool existsPath = hasPath(x, y, visited);
        delete[] visited;
        return existsPath;
    }

    void printEdges(){
        for(int i=0; i<numVertexes; ++i){
            for(int j=0; j<numVertexes; ++j){
                cout<<e[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }


};

bool isConnected(Graph * g){

    for(int i=0; i<g->getNumVertexes(); ++i){
        for(int j=0; j<g->getNumVertexes(); ++j){
            if(!g->isPath(i, j) && !g->isPath(j,i))
                return false;
            }
        }
    return true;
}



int main()
{
    //int numVetexes = 6;
    //int numEdges = 7;
    int numVetexes = 3;
    int numEdges = 2;
    int ** ed = new int*[numEdges];
    for(int i=0; i<numEdges; ++i)
        ed[i] = new int[2];
    /* Connected
    int e[7][2] = {{0,1},
                    {1,2},
                    {2,3},
                    {0,3},
                    {3,4},
                    {4,5},
                    {5,0}};
    */
    //Not connected
    int e[2][2] = {{0, 1}, {0, 2}};

    for(int i=0; i<numEdges ;++i){
        ed[i][0] = e[i][0];
        ed[i][1] = e[i][1];
    }

    Graph * g = new Graph(numVetexes, ed, numEdges);

    g->printEdges();
    cout << isConnected(g) << endl;
    return 0;
}
