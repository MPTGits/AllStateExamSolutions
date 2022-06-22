#include <iostream>

using namespace std;

bool binSearch(int x, int a[], int size){
    if(size == 0) return false;
    return a[size/2] == x? true: (a[size/2]<x && binSearch(x, a, size + size/4))? true: (binSearch(x, a, size/2));
    }


int main()
{

    int arr[5] = {2, 5, 10, 12 , 15};
    cout << binSearch(1, arr, 5)<< endl;
    return 0;
}
