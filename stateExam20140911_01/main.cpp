#include <iostream>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;


struct Point{
    int x;
    int y;
    Point(int a=-1, int b=-1): x(a), y(b){};

    friend ostream& operator<<(ostream& os, const Point & p){
        os<<"("<<p.x<<", "<<p.y<<")"<<endl;
        return os;
    }

    bool operator==(const Point & p){
        return x == p.x && y == p.y;
    }

    bool isAdjecent(const Point & p){
        vector<Point> v;
        for(int i=-1; i<=1; ++i){
            for(int j=-1; j<=1; ++j){
                if(p.x == x+i && p.y == y+j) return true;
            }
        }
        return false;
    }

};

class GamePlayer{
protected:
    Point pos;
    int ** gameboard;
    int bSize;
    void copyData(const GamePlayer & o){
        bSize = o.bSize;
        pos = o.pos;
        gameboard = new int*[bSize];
        for(int i=0; i<bSize; ++i)
            gameboard[i] = new int[bSize];
        for(int i=0; i<bSize; ++i)
            for(int j=0;j<bSize;++j)
                gameboard[i][j] = o.gameboard[i][j];
    }
    void deleteData(){
        for(int i=0;i<bSize; ++i)
            delete[] gameboard[i];
        delete[] gameboard;
    }
public:
    GamePlayer(){
        gameboard = nullptr;
        bSize = 0;
    }

    GamePlayer(int ** gb, int size, Point cord){
        assert(cord.x>-1 && cord.x<size && cord.y>-1 && cord.y<size);
        bSize = size;
        pos = cord;
        gameboard = new int*[bSize];
        for(int i=0; i<bSize; ++i)
            gameboard[i]=new int[bSize];
        for(int i = 0; i<bSize; ++i)
            for(int j=0; j<bSize; ++j)
            gameboard[i][j] = gb[i][j];
    }

    GamePlayer(const GamePlayer & o){
        copyData(o);
    }

    GamePlayer& operator=(const GamePlayer & o){
        if(this!=&o){
            deleteData();
            copyData(o);
        }
        return *this;
    }

    virtual ~GamePlayer(){
        deleteData();
    }

    Point getPos(){
        return pos;
    }


    virtual vector<Point> allowedMoves()=0;
    virtual void sayType()=0;


};


class Knight: public GamePlayer{
public:
    Knight(int ** gb, int size, Point cord): GamePlayer(gb, size, cord){};

    vector<Point> allowedMoves(){
        vector<Point> v;
        for(int i=-1; i<=1; ++i){
            for(int j=-1; j<=1; ++j){
                if(pos.x+i>=0 && pos.x+i<=bSize-1 && pos.y+j>=0 && pos.y+j<=bSize-1 && gameboard[pos.x+i][pos.y+j] == 0){
                    bool isSafe = true;
                    int x = pos.x+i, y = pos.y+j;
                    for(int k=-1; k<=1; ++k){
                        for(int f=-1; f<=1; ++f){
                            if(isSafe && x+k>=0 && x+k <=bSize-1 && y+f>=0 && y+f<=bSize-1 && gameboard[x+k][y+f] == 1){
                                isSafe = false;
                            }
                        }
                    }
                    if(isSafe){
                        v.push_back(Point(pos.x+i, pos.y+j));
                    }
                }
            }
        }
        return v;
    }

    void sayType(){
        cout<<"Knight";
    }
};


class SeaMonster: public GamePlayer{
public:
    SeaMonster(int ** gb, int size, Point cord): GamePlayer(gb, size, cord){};

    vector<Point> allowedMoves(){
        vector<Point> v;
        int counter = pos.x+1;
        while(counter<bSize && gameboard[counter][pos.y] == 2){
                v.push_back(Point(counter, pos.y));
                ++counter;
        }
        counter = pos.x-1;
        while(counter>=0 && gameboard[counter][pos.y] == 2){
                v.push_back(Point(counter, pos.y));
                --counter;
        }
        counter = pos.y-1;
        while(counter>=0 && gameboard[pos.x][counter] == 2){
                v.push_back(Point(pos.x, counter));
                --counter;
        }
        counter = pos.y+1;
        while(counter<bSize && gameboard[pos.x][counter] == 2){
                v.push_back(Point(pos.x, counter));
                ++counter;
        }
        return v;
    }

    void sayType(){
        cout<<"Sea Monster";
    }
};

void allMoves(GamePlayer ** gp, int numPlayers){
    for(int i=0; i< numPlayers; ++i){
        vector<Point> allowedMoves = gp[i]->allowedMoves();
        for(int k=0; k<allowedMoves.size(); ++k){
            int playersAdjecent = 0;
            for(int j=0; j<numPlayers; ++j){
                if(j!=i){
                    vector<Point> otherPlayerMoves = gp[j]->allowedMoves();
                    for(int f=0; f<otherPlayerMoves.size(); ++f){
                        if(otherPlayerMoves[f].isAdjecent(allowedMoves[k])){
                            ++playersAdjecent;
                            break;
                        }
                    }
                }
            }
        if(playersAdjecent == numPlayers-1){
                gp[i]->sayType();
                cout<<"->"<<allowedMoves[k];
        }
        }
    }

}


int main()
{

    int gb[5][5] = {
    {1, 1, 0, 2, 0},
    {0, 2, 1, 0, 2},
    {2, 2, 2, 2, 1},
    {1, 0, 2, 2, 0},
    {0, 2, 0, 2, 1}
    };

    int ** mainGb = new int*[5];
    for(int i=0; i<5; ++i)
        mainGb[i] = new int[5];

    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
            mainGb[i][j] = gb[i][j];

    GamePlayer * k = new Knight(mainGb, 5, Point(3, 1));
    vector<Point> v = k->allowedMoves();
    for(int i=0; i<v.size(); ++i)
        cout<<v[i];


    cout<<"=============="<<endl;

     GamePlayer * sm = new SeaMonster(mainGb, 5, Point(2, 2));
     vector<Point> v2 = sm->allowedMoves();
     for(int i=0; i<v2.size(); ++i)
         cout<<v2[i];

    cout<<"================"<<endl;

    GamePlayer * gpStack[2] = {k, sm};

    allMoves(gpStack, 2);


    for(int i=0; i<5; ++i)
        delete[] mainGb[i];
    delete[] mainGb;

    return 0;
}
