#include <iostream>
#include <string.h>


using namespace std;


void swap(char* str, int i, int j){
    char t = str[i];
    str[i] = str[j];
    str[j] = t;
}

void reverse_string(char* str, int length){
    int start = 0;
    int end = length-1;

    while(start<=end){
        if((str[start] >= 'a' && str[start] <= 'z') ||
              (str[start] >= 'A' && str[start] <= 'Z') ||
              (str[start] >= '0' && str[start] <= '9') ||
              str[start] == '_'){
            if((str[end] >= 'a' && str[end] <= 'z') ||
              (str[end] >= 'A' && str[end] <= 'Z') ||
              (str[end] >= '0' && str[end] <= '9') ||
              str[end] == '_'){
                swap(str, start, end);
              } else{
                end--;
                continue;
              }
        } else{
            start++;
            continue;
        }
    start++;
    end--;
    }
}
void reverse_words(char* str){
    int l = strlen(str);
    //Reverse string
    reverse_string(str,strlen(str));
    int p=0;
    //Find word boundaries and reverse word by word
    for(int i=0; i<l; i++){
        if(str[i] == ' '){
            reverse_string(&str[p], i-p);
            p=i+1;
        }
    }
    //Finally reverse the last word.
    reverse_string(&str[p], l-p);
}



int main()
{
    char text[40] = "conquest , is , ; a test";
    reverse_words(text);
    for(int i =0; i<strlen(text); ++i){
        cout<<text[i];
    }


    return 0;
}
