#include <iostream>
#include <string.h>
#include <map>

using namespace std;

int countAnagrams(char ** matrix, int size){
    int currentAnagrams = 0, maxAnagrams = 0;
    bool isAnagram = true;
    for(int i = 0; i< size; ++i){
        map<char, int> m;
        for(int j=0; j<strlen(matrix[i]); ++j){
            if(m.find(matrix[i][j]) != m.end()){
                m[matrix[i][j]]++;
            } else {
                m[matrix[i][j]] = 1;
            }
        }
        for(int j=i+1; j<size; ++j){
            map<char, int> tmp = m;
            for(int k=0; k<strlen(matrix[j]); ++k){
                if((tmp.find(matrix[j][k]) != m.end()) && tmp[matrix[j][k]]>0){
                    tmp[matrix[j][k]]--;
                } else{
                    isAnagram = false;
                    break;
                }
            }
            if(isAnagram) {
                currentAnagrams = currentAnagrams>0? currentAnagrams+1: currentAnagrams+2;
            }
            isAnagram=true;
        }
        if(currentAnagrams>maxAnagrams) maxAnagrams = currentAnagrams;
        currentAnagrams = 0;
    }

    return maxAnagrams;
}


int main()
{
    int n = 2;
    int k;
    for(k = 1; k<5000; k=(k<<2)-1) {
        cout<<(k<<2)-1<<endl;
        if(k%11==0){
            break;
        }
    }

    int numAnagrams;
    cout<<"Enter number of anagarms:"<<endl;
    cin>>numAnagrams;
    cin.ignore();
    char ** anagrams = new char*[numAnagrams];
    char anagram[50];
    for(int i=0; i<numAnagrams; ++i){
        cin.getline(anagram, 50);
        anagrams[i] = new char[strlen(anagram)];
        strcpy(anagrams[i], anagram);
    }

    cout<<"Number of anagrams:"<<countAnagrams(anagrams, numAnagrams);

    for(int i =0; i< numAnagrams; ++i)
        delete[] anagrams[i];

    delete[] anagrams;

    return 0;
}
