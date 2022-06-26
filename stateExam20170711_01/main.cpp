#include <iostream>

using namespace std;

void envForrestChange(char arr[][100], int n, int m){
    int ** currArray = new int*[n];
    for(int i=0; i<n; ++i)
        currArray[i] = new int[m];

    for(int x = 0; x<n; ++x)
            for(int y=0; y<m; ++y)
                currArray[x][y] = 0;

    for(int i =0; i<2; ++i){
        for(int x = 0; x<n; ++x)
            for(int y=0; y<m; ++y)
                arr[x][y] = char(arr[x][y]+currArray[x][y]);
        for(int x = 0; x<n; ++x)
            for(int y=0; y<m; ++y)
                currArray[x][y] = 0;

        for(int x = 0; x<n; ++x){
            for(int y=0; y<m; ++y){
                if(arr[x][y] == '4'){
                    int count = 0;
                    for(int k=-1; k<=1; ++k){
                        for(int l=-1; l<=1; ++l){
                            if(count >= 3){
                                currArray[x][y] = -1;
                                break;
                            }
                            if(x+k>=0 && x+k<=n-1 && y+l >= 0 && y+l<=m-1 && arr[x+k][y+l] == '3'){
                                count++;
                            }
                        }
                    }
                } else if(arr[x][y] >= '0' && arr[x][y]<='3'){
                    currArray[x][y] = 1;
                }
            }
        }
    }

    for(int x = 0; x<n; ++x)
            for(int y=0; y<m; ++y)
                arr[x][y] = char(arr[x][y]+currArray[x][y]);

    for(int x = 0; x<n; ++x){
        for(int y=0; y<m; ++y){
            cout<<arr[x][y]<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    char arr [100][100] = {
    {'R', 'R', '1', '1', '2', '2'},
    {'1', '4', 'R', 'R', '2', '2'},
    {'S', '4', '4', '4', '2', '3'},
    {'4', '4', 'S', 'S', 'R', 'R'}
    };

    envForrestChange(arr, 4, 6);
    return 0;
}
