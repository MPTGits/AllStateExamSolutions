#include <iostream>
#include <math.h>

using namespace std;

void square(float * x, float * y, int n){
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(x[i]>x[j]){
                cout<<x[i]<<endl;
                float tmp = x[i];
                x[i] = x[j];
                x[j] = tmp;
            }
            if(y[i]>y[j]){
                float tmp = y[i];
                y[i] = y[j];
                y[j] = tmp;
            }
        }
    }
    float squareSize = (fabs(x[0]-x[n-1]) > fabs(y[0]-y[n-1]))? fabs(x[0]-x[n-1]):fabs(y[0]-y[n-1]);
    cout<<"("<<(x[0]+squareSize)/2<<", "<<(y[0]+squareSize)/2<<") ";
    cout<<squareSize;

}



int main()
{
    float x[5] = {0, 3, 2, 4, 6};
    float y[5] = {1, -2, 3, 5, 2};
    square(x, y, 5);
    return 0;
}
