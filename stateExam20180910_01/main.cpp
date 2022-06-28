#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int smallerOrderTitle(char * title1, char * title2){
    int smallerTitle = strlen(title1)>strlen(title2)? strlen(title2): strlen(title1);

    for(int i = 0; i<smallerTitle; i++){
        if(abs('A' - title1[i]) > abs('A' - title2[i])){
            return 1;
        }
        else if(abs('A' - title1[i]) < abs('A' - title2[i])){
            return -1;
        }
    }

    if(strlen(title1) == strlen(title2)) return 0;

    return strlen(title1) > strlen(title2)? 1: -1;
}

vector<int> extractBookPasswordSeq(char * bookTitle){
    vector<int> v; int count =0;
    for(int i = 0; i< strlen(bookTitle); ++i){
        if(bookTitle[i] == ' '){
            if(count){
                v.push_back(count);
            }
            count = 0;
        } else {
            count++;
        }
    }
    if(count > 0){
        v.push_back(count);
    }

    return v;

}


void revealPassword(char arr[20][30][100], int m, int n){
    vector<int> passwordSequence;
    for(int i=0;i<m;++i){
        bool isSorted = true;
        for(int j=0;j<n-1;++j){
            if(smallerOrderTitle(arr[i][j], arr[i][j+1]) == -1){
                isSorted = false;
                break;
            }
        }
        if(isSorted){
            int middle = (m%2==0)?m/2-1:m/2;
            vector<int> passWord = extractBookPasswordSeq(arr[i][middle]);
            for(int k=0; k<passWord.size(); ++k){
                passwordSequence.push_back(passWord[k]);
            }
        }
    }

    for(int i =0; i<passwordSequence.size(); ++i){
        cout<<passwordSequence[i]<<" ";
    }

}




int main()
{
    char book[100];
    char shelve[20][30][100] = {
    {"Алгебра", "Аналитична геометрия", "Математически анализ", "Юпитер"},
    {"Абуба", "Баските бее", "Структури от данни и", "Карлос"},
    {"Бази от данни", "Изкуствен интелект", "Функционално програмиране", "Щека"},
    } ;
    /*
    int m,n;
    cout<<"Input number of rows:";
    cin>>m;
    cout<<endl;
    cout<<"Input number of books per row:";
    cin>>n;
    cout<<endl;
    cin.clear();
    cin.ignore();
    for(int i = 0; i< m; ++i){
        for(int j=0; j<n; ++j){
            cout<<"Input book "<<i<<" "<<j<<" title:";
            cin.getline(book, 100);
            strcpy(shelve[i][j], book);
            cout<<endl;
        }
    }
    */
    revealPassword(shelve, 3, 3);
    return 0;
}
