#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double matrix[5][4] = { {2,2,4,8},
                            {4,5,6,1},
                            {2,4,8,0},
                            {6,3,6,1}
                            };
    double e = 0.000001;
    bool isMatch = true;
    double comparer;
    for(int i=0;i<5;++i){
        for(int j=i+1;j<5;++j){
            for(int k=0;k<4;++k){
                if(k==0 && matrix[j][k]!=0){
                    comparer = matrix[i][k]/matrix[j][k];
                    continue;
                }
                if(matrix[j][k] == 0 || (fabs((matrix[i][k]/matrix[j][k])-comparer)>e)){
                    isMatch = false;
                    break;
                }
                if(isMatch){
                    cout<<"yes";
                    return 0;
                }
            isMatch = true;
            }
        }
    }
    cout<<"no";

    return 0;
}
