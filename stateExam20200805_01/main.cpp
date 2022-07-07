#include <iostream>
#include <string.h>


using namespace std;

const char * findWordStart(const char * start, const char * end){
    if (start == end) return start;
    return int(*(start)) <= 32? findWordStart(start+1,end): start;
}

const char * findWordEnd(const char * start, const char * end){
    if (start == end) return start;
    return int(*(start)) > 32? findWordEnd(start+1,end): start;
}

void print_word(const char * start, const char * end){
    if(start == end)
    {
        cout<<*start<<" ";
        return;
    }
    cout<<*start;
    print_word(start+1, end);
}

void print_backwards(const char * start, const char * end){
    const char * wordStart = findWordStart(start, end);
    const char * wordEnd = findWordEnd(wordStart, end);
    if(wordStart<end){
        print_backwards(wordEnd, end);
        print_word(wordStart, wordEnd);
    }

}

void print_backwards(const char * text){
    print_backwards(text, text+strlen(text)-1);
}


int main()
{
    print_backwards("I\tneed a break!");
    return 0;
}
