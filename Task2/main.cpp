/* ������ 1.6.[1] �� �� ������ ��������, ����� �� �������� ���������
������ ������ ������������� ���� �� �����, ��������, �������� � ��-
�������, ����� � ����� ����� �� ���������� �� ���������� ������.
*/
#include <iostream>

using namespace std;


int main()
{
    int yearsLived;
    cout<<"Input the number of years you have lived:";
    cin>>yearsLived;
    int startYear = 2022-yearsLived;
    int addon, days = 0, hours=0, mins=0, secs=0;
    for(int i = startYear; i<2022; ++i){
        addon = ((i%4==0 && i%100 != 0) || (i%100 == 0 && i%400 == 0)) ? 366:365;
        days += addon;
        hours += addon*24;
        mins += addon*24*60;
        secs += addon*24*60*60;
    }
    cout<<"Days lived:"<<days<<endl;
    cout<<"Hours lived:"<<hours<<endl;
    cout<<"Minutes lived:"<<mins<<endl;
    cout<<"Seconds lived:"<<secs<<endl;
    return 0;
}
