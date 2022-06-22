#include <iostream>
#include <cmath>

using namespace std;

void subsample(float img[][10], int m, int n){
    int sizeX = floor((m+1)/2), sizeY=floor((n+1)/2);
    float ** res = new float*[sizeX];
    for(int i=0; i<floor((n+1)/2); ++i)
        res[i] = new float[sizeY];

    for(int i=0; i<sizeX; ++i){
        for(int j=0; j<sizeY; ++j){
            float sum=0;
            int count=0;
            for(int x=2*j; x<=(2*j)+1; ++x){
                for(int y=2*i; y<=(2*i)+1; ++y){
                    if(y>=0 && y<=m-1 && x>=0 && x<=n-1){
                        sum += img[y][x];
                        count++;
                    }
                }
            }
            res[i][j] = count>0? float(sum)/float(count): 0;
        }
    }

    for(int i=0; i<sizeX; ++i){
        for(int j=0; j<sizeY; ++j){
            cout<<res[i][j]<<" ";
        cout<<endl;
        }
    };

    for(int i=0; i<sizeY; ++i)
        delete[] res;
    delete[] res;
}



int main()
{
    float arr[10][10] = {{1.0, 2.0, 3.0}, {4.5, 6.5, 7.5}};
    subsample(arr, 2, 3);
    return 0;
}
