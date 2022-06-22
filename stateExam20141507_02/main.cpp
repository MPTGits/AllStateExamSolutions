#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;


struct ChessPosition{
    char row;
    int col;
    ChessPosition(char r, int c){
        assert(r>='A' && r<='H');
        assert(c>=1 && c<=8);
        row = r; col = c;
    }

    bool operator==(ChessPosition const & o){
        return row == o.row && col == o.col;
    }
};


class ChessPiece{
    public:
        ChessPosition cord;

    public:
        ChessPiece(ChessPosition pos): cord(pos){};
        virtual vector<ChessPosition> allowedMoves() = 0;
        virtual bool captures(ChessPosition pos) = 0;
        virtual ~ChessPiece(){};

};

class Rook: public ChessPiece{
    public:
        Rook(ChessPosition pos): ChessPiece(pos){};

        virtual vector<ChessPosition> allowedMoves(){
            vector<ChessPosition> v;
            for(int i=cord.col+1; i<9; ++i){
                v.push_back(ChessPosition(cord.row, i));
            };
            for(int i=cord.col-1; i>0; --i){
                v.push_back(ChessPosition(cord.row, i));
            };
            for(int i=cord.row-1; i>='A'; --i){
                v.push_back(ChessPosition(char(i), cord.col));
            };
            for(int i=cord.row+1; i<='H'; ++i){
                v.push_back(ChessPosition(char(i), cord.col));
            };
            return v;
        };

        virtual bool captures(ChessPosition pos){
            return (pos.row == cord.row || pos.col == cord.col) && !(pos.row == cord.row && pos.col == cord.col) ;
        };

};

class Knight: public ChessPiece{
    public:
        Knight(ChessPosition pos): ChessPiece(pos){};

        virtual vector<ChessPosition> allowedMoves(){
            vector<ChessPosition> v;
            for(int i=cord.col+1; i<9; ++i){
                v.push_back(ChessPosition(cord.row, i));
            };
            for(int i=cord.col-1; i>0; --i){
                v.push_back(ChessPosition(cord.row, i));
            };
            for(int i=cord.row-1; i>='A'; --i){
                v.push_back(ChessPosition(char(i), cord.col));
            };
            for(int i=cord.row+1; i<='H'; ++i){
                v.push_back(ChessPosition(char(i), cord.col));
            };
            for(int i=cord.row+1, j=cord.col+1; i<='H' && j<=8; ++i, ++j){
                v.push_back(ChessPosition(char(i), j));
            };
            for(int i=cord.row-1, j=cord.col-1; i>='A' && j>=1; --i, --j){
                v.push_back(ChessPosition(char(i), j));
            };
            for(int i=cord.row-1, j=cord.col+1; i>='A' && j<=8; --i, ++j){
                v.push_back(ChessPosition(char(i), j));
            };
            for(int i=cord.row+1, j=cord.col-1; i<='H' && j>=1; ++i, --j){
                v.push_back(ChessPosition(char(i), j));
            };
            return v;
        };

        virtual bool captures(ChessPosition pos){
            if (pos.row == cord.row && pos.col == cord.col)  return false;
            if (pos.row == cord.row || pos.col == cord.col) return true;
            for(int i =0; i<9; ++i){
                if(cord.col + i == pos.col && char(cord.row+i) == pos.row) return true;
                if(cord.col - i == pos.col && char(cord.row-i) == pos.row) return true;
                if(cord.col + i == pos.col && char(cord.row-i) == pos.row) return true;
                if(cord.col - i == pos.col && char(cord.row+i) == pos.row) return true;
            }
            return false;
        };

};


void allMoves(ChessPiece ** pices, int numPices, int currPieceIndex, vector<ChessPosition> & moves){
    if(currPieceIndex == numPices){
        for(int i=0; i<moves.size(); ++i){
            cout<<moves[i].row<<moves[i].col<<" ";
        }
        cout<<endl;
    }
    for(int i=currPieceIndex; i<numPices; ++i){
        vector<ChessPosition> posMoves = pices[i]->allowedMoves();
        bool isGood = true;
        ChessPosition old = pices[i]->cord;
        for(int j = 0; j<posMoves.size();++j){
            pices[i]->cord = posMoves[j];
            for (int k = 0; k<moves.size(); ++k){
                if ((pices[k]->captures(posMoves[j]) || pices[i]->captures(pices[k]->cord)) && !(moves[k].row == posMoves[j].row && moves[k].col == posMoves[j].col)){
                    isGood = false;
                    break;
                }
            }
            if(isGood){
                moves.push_back(posMoves[j]);
                allMoves(pices, numPices, currPieceIndex+1, moves);
                moves.pop_back();
            }
            pices[i]->cord = old;
        }
    }


}


int main()
{
    ChessPosition p('C', 2);
    ChessPiece * cp = new Rook(p);
    vector<ChessPosition> v = cp->allowedMoves();
    //for(int i =0; i<v.size(); ++i){
       // cout<<v[i].row<<v[i].col<<endl;
    //}
    p.col++;
    cout<<cp->captures(p)<<endl;

    ChessPosition p2('D', 6);
    ChessPiece * cp2 = new Knight(p2);
    vector<ChessPosition> v2 = cp2->allowedMoves();
    //for(int i =0; i<v2.size(); ++i){
    //    cout<<v2[i].row<<v2[i].col<<endl;
    //}
    p2.col++;
    cout<<cp2->captures(p2)<<endl;

    ChessPiece * pices[2] = {cp, cp2};
    vector<ChessPosition> moves;
    allMoves(pices, 2, 0, moves);
    return 0;
}
