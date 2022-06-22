#include <iostream>

using namespace std;

void symetricConversion(double arr[][11]){
    double translatedMatrix[11][11];
    for(int i=0; i<11; ++i){
        for(int j=0; j<11; ++j){
            double sum = 0;
            if(i==j){
                cout<<"For ["<<i<<", "<<j<<"] summing:"<<"["<<i<<", "<<j<<"], "<<"["<<10-i<<", "<<10-j<<"]"<<endl;
                sum = arr[i][j] + arr[10-i][10-j];
            }
            else if(i+j == 10){
                    cout<<"For ["<<i<<", "<<j<<"] summing:"<<"["<<i<<", "<<j<<"], "<<"["<<j<<", "<<i<<"]"<<endl;
                    sum = arr[i][j] + arr[j][i];
            }
            else{
                cout<<"For ["<<i<<", "<<j<<"] summing:"<<"["<<i<<", "<<j<<"], "<<"["<<j<<", "<<i<<"], "<<"["<<10-i<<", "<<10-j<<"], "<<"["<<10-j<<", "<<10-i<<"]"<<endl;
                sum = arr[i][j] + arr[j][i] + arr[10-i][10-j] + arr[10-j][10-i];
            }
            translatedMatrix[i][j] = sum;
        }
    }
    for(int i=0; i<11; ++i)
        for(int j=0; j<11; ++j)
            arr[i][j] = translatedMatrix[i][j];
}


int main()
{

    double arr[11][11] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
    };

    symetricConversion(arr);

    for(int i=0; i<11; ++i){
        for(int j=0; j<11; ++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }



    cout << "Hello world!" << endl;
    return 0;
}
