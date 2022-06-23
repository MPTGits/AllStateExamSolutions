#include <iostream>
#include <string.h>

using namespace std;

pair<int, int> getBiggestDistance(const char * s){
    int biggestDistance = 0;
    pair<int, int> p(0, 0);
    for(int i=0; i<strlen(s); ++i){
        for(int j=i+1; j<strlen(s); ++j){
            if(s[i] == s[j] && j-i>biggestDistance){
                p.first = i;
                p.second = j;
                biggestDistance = j-i;
            }
        }
    }
    return p;
}

int main()
{
    pair<int, int> p;
    p = getBiggestDistance("abacdefgha");
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}
