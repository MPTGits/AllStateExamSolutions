#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool comp(int a, int b){
    return a>b;
}

int traverseDFS(char arr[][100], int i, int j, int n, int m, vector<pair<int, int>> & v){
    if(i>=n || i<0 || j>=m || j<0 || arr[i][j] != '4'){
            return 0;
    }
    for(int k=0; k<v.size(); ++k){
        if(v[k].first == i && v[k].second == j) return 0;
    }
    pair<int, int> p(i, j);
    v.push_back(p);
    int curr = 1 + traverseDFS(arr, i+1, j, n, m, v)+ traverseDFS(arr, i-1, j, n, m, v) + traverseDFS(arr, i, j+1, n, m, v) + traverseDFS(arr, i, j-1, n, m, v);
    v.pop_back();
    return curr;
}

int maxForrestArea(char arr[][100], int n, int m){
    int maxArea = 0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(arr[i][j] == '4'){
                vector<pair<int, int>> visited;
                int curr = traverseDFS(arr, i, j, n, m, visited);
                if(curr>maxArea) maxArea = curr;
            }
        }
    }
    return maxArea;

}


int main()
{

    char arr [100][100] = {
    {'R', 'R', '1', '1', '2', '2'},
    {'1', '4', 'R', 'R', '1', '2'},
    {'S', '4', '4', '4', '2', '3'},
    {'4', '4', 'S', 'S', 'R', 'R'}};
    cout << maxForrestArea(arr, 4, 6) << endl;
    return 0;
}
