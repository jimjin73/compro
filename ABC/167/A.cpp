#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s,t;

int main(){
    cin >> s;
    cin >> t;
    for(int i=0;i<s.size();i++){
        if(s[i] != t[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}