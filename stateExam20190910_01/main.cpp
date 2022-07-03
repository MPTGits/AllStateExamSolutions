#include <iostream>
#include <string.h>

using namespace std;

bool find(int val, int * arr, size_t size){
    for(int i = 0; i< size; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
    if(size == 0) return false;
    size_t mid = size/2;
    if(val == arr[mid]) return true;

    if(val < arr[mid])
        return find(val, arr, mid);
    else
    return find(val, arr+mid, mid);

}

template <typename ReturnType, typename InputType, typename OpType>
ReturnType fold_left(InputType* arr, size_t size, OpType op, ReturnType nil){
    ReturnType result = nil;
    for(size_t i = 0; i< size; ++i)
        result = op(arr[i], result);
    return result;
}

int op(char Digit, int Result){
    return (Result * 10) + (Digit - '0');
}

int str_to_int(const char * str){
    return (str == nullptr)? 0: fold_left(str, strlen(str), op, 0);
}



int main()
{
    int arr[10] = {4, 5, 7 ,10, 15, 16, 19, 20};
    cout<<find(10, arr, 8);
    cout<<endl;
    cout<<str_to_int("2451") + 10;
    return 0;
}
