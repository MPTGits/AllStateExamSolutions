#include <iostream>

using namespace std;
//1.1. Превърнете рожденната си дата шестнадесетична, в осмична и в двоична бройна система

void convertNumberToBinary(int n){
    if (n == 0){
        return;
    }
    convertNumberToBinary(n/2);
    cout<<(n % 2);
}


void convertBirthdayToBinary(int day, int month, int year){
    convertNumberToBinary(day);
    cout<<" ";
    convertNumberToBinary(month);
    cout<<" ";
    convertNumberToBinary(year);
}


int main()
{
    char birthday[20];
    char currResolver[20];
    cin.getline(birthday, 20);
    int currIdx = 0;
    for(int i = 0; birthday[i]; i++){
        if(birthday[i] == ' '){
            convertNumberToBinary(atoi(currResolver));
            cout<<endl;
        }
        else {
        currResolver[i] = birthday[i];
        }
    }

    //convertBirthdayToBinary(day, month, year);
    return 0;
}
