#include <iostream>
using namespace std;
char find(string a, string b){
    char r = 0;
    
    for(int i=0;i<a.size();i++){
        r^=a[i];
    }
    for(int i=0;i<b.size();i++){
        r^=b[i];
    }
    return r;
}
int main(){
    string a = "apple";
    string b = "applep";
    cout << find(a,b);
}