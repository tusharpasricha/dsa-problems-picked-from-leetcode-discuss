// A data analyst recently joined HackerRank as an intern.
// As an initial task, data for n days is provided to the intern. Then, k updates are performed on the data, where each update is of the form [l, r]. This indicates that the subarray of data starting at
// index / and ending at index ris negated. 
//For example, if data = [1, 2,
// 3, 4] and the updates are [2, 4] then the data becomes data = [1, -2, -3, -4].
// Given the initial data and k updates, find the final data after all updates.
// Note: 1-based indexing is used.
// Example
// 27].
// Consider n = 4, data = [1, -4, -5, 2], k = 2 and updates = [[2, 4], [1,
// 1. After the first update, the data becomes data = [1, 4, 5, -2].
// 2. After the second update, the data becomes data = [-1, -4, 5, -21.
// The final data is (-1, -4, 5, -2].

#include <iostream>
#include<vector>
using namespace std;
void update(vector<int>&data,int n , vector<pair<int,int>> updates, int k){
    for(int i=0;i<k;i++){
        for(int j=updates[i].first -1 ;j<updates[i].second;j++){
            data[j] = data[j]*-1;
        }
    }
}

int main(){
    int n=4;
    vector<int>data = {1,-4,-5,2};
    int k=2;
    vector<pair<int,int>> updates={{2,4},{1,2}};
    update(data,n,updates,k);
    for(int i=0;i<data.size();i++){
        cout<<data[i]<<" ";
    }
}