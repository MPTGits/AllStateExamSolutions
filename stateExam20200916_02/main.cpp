#include <iostream>
#include <string.h>


using namespace std;

bool subordinate(const char * employee,
                 const char * manager,
                 const char * leaders [][2],
                 size_t size){
    if(strcmp(employee, manager) == 0) return false;
    for(int i = 0; i< size; ++i){
        if(strcmp(employee, leaders[i][0]) == 0){
            if(strcmp(manager, leaders[i][1]) == 0){
                return true;
            }
            return subordinate(leaders[i][1], manager, leaders, size);
        }
    }

    return false;

}

const char * bigBoss(const char * leaders [][2], size_t size){
    for(int i =0; i<size; ++i){
        bool hasManager = false;
        for(int j = 0; j<size; ++j){
            if(strcmp(leaders[i][1], leaders[j][0]) == 0){
                hasManager = true;
                break;
            }
        }
        if (!hasManager) return leaders[i][1];
    }

}



int main()
{
    const char * arr[4][2] = {
        {"Иван Иванов", "Мария Иванова"},
        {"Мария Иванова", "Иван Драганов"},
        {"Иван Драганов", "Stoyan Petrov"},
        {"Петко Христов", "Stoyan Petrov"},
    };

    cout<<subordinate("Иван Иванов", "Stoyan Petrov", arr, 4)<<endl;
    cout<<bigBoss(arr, 4)<<endl;;
    return 0;
}
