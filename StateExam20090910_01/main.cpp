#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char seq[5][10];
    for(int i=0;i<5;++i){
        cin.getline(seq[i], 50);
    }

    int currSeqIdex =0, foundMatches;

    for(int i=0; i<5; ++i){
        foundMatches = 0;
        for(int j=0;j<5; ++j){
            if(j==i) continue;
            if(strlen(seq[j])> strlen(seq[i])){
                break;
            }
            for(int k=0;k<strlen(seq[i]); ++k){
                if(currSeqIdex<strlen(seq[j]) && seq[i][k]==seq[j][currSeqIdex]){
                    currSeqIdex++;
                } else{
                    currSeqIdex = 0;
                }
                if(currSeqIdex==strlen(seq[j])){
                    foundMatches++;
                    break;
                }
            }
            currSeqIdex = 0;
            if(foundMatches == 4){
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
    return 0;
}
