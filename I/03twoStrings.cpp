
// 1. Two Strings
// Given two arrays of strings, determine whether corresponding elements contain a common substring.
// For example, if array a = [ab,cd,ef] and array b = [laf, ee, eff] we make the following decisions:
// For each test, print your result on a new line, either YES if there is a common substring, or NO. 
// Function Description
// Complete the function commonSubstring in the editor below. For each ali], bi] pair, the function must print YES if they share a common substring, or NO on a new line.
// commonSubstring has the following parameters):
// a[a[0],..a[n-1]]: an array of strings b[bO],..b[n-1]]: an array of strings


//https://leetcode.com/discuss/interview-question/406151/IBM-or-OA-2019-or-Two-Strings-or-Backend
//two strings

#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool common(string s1, string s2){
    // vector<bool>mp(52,false);

    // for(int i=0;i<s1.size();i++){
    //     mp[s1[i]- 'a'] = true;
    // }
    // for(int i=0;i<s2.size();i++){
    //     if(mp[s2[i]-'a']){
    //         return true;
    //     }
    // }
    // return false;
    unordered_set<char>st(s1.begin(),s1.end());
    for(int i=0;i<s2.size();i++){
        if(st.find(s2[i]) != st.end()){ // if the character is found in the set
                return true;
        }
    }
    return false;
    // Using unordered_set: This data structure allows for average O(1) time complexity for insertions and lookups.

}

vector<string>sol(vector<string>s1,vector<string>s2){
    vector<string>ans;
    for(int i = 0;i<s1.size();i++){
        if(common(s1[i],s2[i])){
            ans.push_back("YES");
        }
        else{
            ans.push_back("NO");
        }
    }
    return ans;
}

int main(){
    vector<string>s1;
    s1.push_back("hello");
    s1.push_back("hi");
    
    vector<string>s2;
    s2.push_back("word");
    s2.push_back("bye");
  
    vector<string>ans = sol(s1,s2);
    for(int i =0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}


