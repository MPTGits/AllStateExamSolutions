#include <iostream>
#include <string.h>

using namespace std;

bool DFS(int  matrix[][10], char * directions, int startRow, int startCol, int currCharIndex){
    cout<<"["<<startRow<<"]"<<"["<<startCol<<"]"<<"->"<<directions[currCharIndex]<<" "<<currCharIndex<<endl;
    if(startRow == 9 && startCol == 9) return true;
    if(currCharIndex>strlen(directions)-1) return false;
    if(startCol<0 || startCol>9 || startRow>9 || startRow<0) return false;
    if(matrix[startRow][startCol] == 1) return false;
    switch(directions[currCharIndex]){
        case 'N':
            DFS(matrix, directions, startRow-1, startCol, currCharIndex+1);
            break;
        case 'E':
            DFS(matrix, directions, startRow, startCol+1, currCharIndex+1);
            break;
        case 'S':
            DFS(matrix, directions, startRow+1, startCol, currCharIndex+1);
            break;
        case 'W':
            DFS(matrix, directions, startRow, startCol-1, currCharIndex+1);
            break;
        default:
            cout<<"Invalid char in directions array"<<endl;
            return false;
    }
}

bool walk(int  matrix[][10], char * directions){
    bool res = false;
    if(strlen(directions) == 0){
        return matrix[9][9] == 0;
    }
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            if(matrix[i][j] == 0){
                cout<<endl;
                res = DFS(matrix, directions, i, j ,0);
                if(res) {
                    cout<<"Found path from ["<<i<<"]"<<"["<<j<<"]"<<endl;
                    return true;
                }
            }
        }
    }
    return false;
}




int main()
{
    int matrix[10][10] = {
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0}
    };

    char directions[] = {};
    //Solution path from [5][4]
    //{'E', 'E', 'E', 'E', 'E', 'S', 'S', 'S', 'S'};
    //Solution path from [0][9]
    //{'S', 'S', 'S' ,'S', 'S' ,'S' ,'S' ,'S' ,'S'};
    //Solution path from [0][0]
    //{'S', 'S', 'S' ,'S', 'S' ,'S' ,'S' ,'S' ,'S','E','E','E', 'N','E','E', 'E','E','E', 'E','S'};

    walk(matrix, directions);
    return 0;
}
