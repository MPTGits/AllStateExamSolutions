#include <iostream>
#include <vector>

using namespace std;

bool isPresent(vector<pair<int, int>> &v, pair<int, int> &p){
    for(int i =0; i<v.size(); ++ i){
        if(v[i] == p) return true;
    }
    return false;
}


void findCurrCellArea(int i, int j, int ** arr, int m, int n, vector<pair<int, int>> &visited,vector<pair<int, int>> &areaIndexes){
    if(j>=m || j<0 || i>=n || i<0 || arr[i][j] == 0){
        return;
    }
    pair<int, int> currPair = make_pair(i, j);
    if(!isPresent(visited, currPair)){
        visited.push_back(currPair);
        areaIndexes.push_back(currPair);
        for(int k = -1; k<=1; ++k)
            for(int f = -1; f<=1; ++f)
                findCurrCellArea(i+k, j+f, arr,m, n, visited, areaIndexes);
    }


}

vector<pair<float, pair<int, int>>> transformAreasAndSort(vector<vector<pair<int, int>>> &areaBrightnessValues, int ** arr){
    vector<pair<float, pair<int, int>>> result;
    for(int i =0; i<areaBrightnessValues.size(); ++i){
        float sum = 0;
        pair<int, int> p = areaBrightnessValues[i][0];
        for(int j = 0; j<areaBrightnessValues[i].size(); ++j){
            sum += arr[areaBrightnessValues[i][j].first][areaBrightnessValues[i][j].second];
        }
        result.push_back(make_pair(sum/areaBrightnessValues[i].size(), p));
    }

    for(int i =0; i<result.size(); ++i){
        for(int j = i+1; j<result.size(); ++j){
            if(result[i].first>result[j].first){
                pair<int, pair<int, int>> tmp = result[i];
                result[i] = result[j];
                result[j] = tmp;
            }
        }
    }

    return result;
}



void averageBrightnessAreas(int ** arr, int m, int n){
    vector<vector<pair<int, int>>> setIndexAreas;
    vector<pair<int, int>> visited;
    for(int i = 0; i<m; ++i){
        for(int j = 0; j<n; ++j){
            vector<pair<int, int>> area;
            findCurrCellArea(i, j, arr, m, n ,visited, area);
            if(!area.empty()){
                setIndexAreas.push_back(area);
            }
        }
    }

    vector<pair<float, pair<int, int>>>areaBrightnessValues;
    areaBrightnessValues = transformAreasAndSort(setIndexAreas, arr);
    for(int i =0; i< areaBrightnessValues.size(); ++i){
     cout<<areaBrightnessValues[i].first<<" ("<<areaBrightnessValues[i].second.first<<","<<areaBrightnessValues[i].second.second<<")"<<endl;
    }
}


int main()
{
    int staticArr[6][6] = {
        {170, 0, 0, 255, 221, 0},
        {68, 0, 17, 0, 0, 68},
        {221, 0, 238, 136, 0, 255},
        {0, 0, 85, 0, 136, 238},
        {238, 17, 0, 68, 0, 255},
        {85, 170, 0, 221, 17, 0}
    };
    int ** arr = new int*[6];
    for(int i = 0; i<6; ++i){
        arr[i] = new int[6];
    }

    for(int i =0; i<6; ++i){
        for(int j =0; j<6; j++){
            arr[i][j] = staticArr[i][j];
        }
    }



    averageBrightnessAreas(arr, 6, 6 );



    cout << "Hello world!" << endl;
    return 0;
}
