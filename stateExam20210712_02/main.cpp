#include <iostream>
#include <unordered_map>

using namespace std;

template <typename T>
struct CustomMap{
private:
    unordered_map<string, T> m;

    string stringifyPair(const pair<int, int> &p){
        return to_string(p.first) + to_string(p.second);
    };

public:
    T operator[](const pair<int, int>& key){
        string keyValue = stringifyPair(key);
        if(m.count(keyValue)) return m[keyValue];
        return 0;
    }

    void insert(pair<int, int> key, T val){
        m[stringifyPair(key)] = val;
    }

};



template<typename T>
CustomMap<T> summedMatrix(CustomMap<T> & m1, CustomMap<T> & m2, int matrixRows, int matrixCols){
  CustomMap<T>  result;
  for(int i =0; i<matrixRows; ++i){
    for(int j =0; j<matrixCols; ++j){
        pair<int, int> p = make_pair(i, j);
        if(m1[p]){
            result.insert(p, m1[p] + result[p]);
        }
        if(m2[p]){
            result.insert(p, m2[p] + result[p]);
        }
    }
  }

  return result;
}



int main()
{
    CustomMap<double> m1;
    m1.insert(make_pair(0,0), 17.5);
    m1.insert(make_pair(0,5), 2);
    m1.insert(make_pair(8,7), 14.2);
    m1.insert(make_pair(14,2), 7);

    CustomMap<double> m2;
    m2.insert(make_pair(0,0), 8.5);
    m2.insert(make_pair(3,5), 8);
    m2.insert(make_pair(8,7), 11.2);
    m2.insert(make_pair(17,11), 19);

    CustomMap<double> res = summedMatrix<double>(m1, m2, 18, 18);

    for(int i =0; i<18; ++i){
        for(int j =0; j<18; ++j){
                cout<<res[make_pair(i,j)]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
