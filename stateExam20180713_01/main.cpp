#include <iostream>

using namespace std;

int numberSize(int n){
    int count = 1;
    while(n>9){
        n /= 10;
        count *= 10;
    }
    return count;
}

int smallerNumber(int a, int b){
    int sizeA = numberSize(a);
    int sizeB = numberSize(b);

    while(a>0 && b>0){
        if((a/sizeA) > (b/sizeB)){
            return 1;
        }
        else if((a/sizeA) < (b/sizeB)){
            return -1;
        }
        a = a - (a/sizeA)*sizeA;
        b = b - (b/sizeB)*sizeB;

        sizeA = sizeA/10;
        sizeB = sizeB/10;
    }
    if(a>0){
        return 1;
    } else if (b>0){
        return -1;
    }

    return 0;
}


int sortLex(int arr[], int n){
    for(int i=0; i<n; ++i){
        for(int j=i+1;j<n;++j){
            if(smallerNumber(arr[i], arr[j]) == 1){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}



int main()
{
   int arr[6] = {13, 14, 7, 2018, 9, 0};
   sortLex(arr, 6);

   for(int i=0; i<6; ++i)
        cout<<arr[i]<<" ";
}
