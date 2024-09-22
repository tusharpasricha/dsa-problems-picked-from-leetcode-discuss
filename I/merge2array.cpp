// 1. Merge 2 Arrays
// Given two sorted arrays, merge them to form a single, sorted array with all items in non-decreasing order.

// a[0] ‹ b[0] → c = [a[0]] = [1]

// a [1] = b[0] → c= [a[0], b[0]] = [1, 2]

// a (1] ‹ b[1] → c = [a[0], 6[0], a(11] = [1, 2, 2]

// a (2] < b[1] → c = [a[0], b[0], a(1], a (2]]= [1, 2, 2, 3)


// Example
// а = [1, 2, 3)
// b = (2, 5, 5)
// Merge the arrays to create array c as follows:
// No more elements in a → c = [a[0], b[0], a[1], a[2], b[1], b(2]] = [1, 2, 2, 3, 5, 5]
// Elements were alternately taken from the arrays in the order given, maintaining precedence.


#include <iostream>
#include <vector>
using namespace std;
void mergearray(vector<int>a,vector<int>b,vector<int>&c){
    int p1 = 0;
    int p2 = 0;
    int s1 = a.size();
    int s2 = b.size();
    while(p1<s1 && p2<s2){
        if(a[p1]<b[p2]){
            c.push_back(a[p1]);
            p1++;
        }
        else{
            c.push_back(b[p2]);
            p2++;
        }
    }
    while(p1<s1){
        c.push_back(a[p1]);
        p1++;
    }
    while(p2<s2){
        c.push_back(b[p2]);
        p2++;
    }
}
int main(){
    vector<int>a = {1,2,3};
    vector<int>b = {2,5,5};
    vector<int>c;
    mergearray(a,b,c);
    for(int i=0;i<c.size();i++){
        cout<<c[i]<<" ";
    }
}