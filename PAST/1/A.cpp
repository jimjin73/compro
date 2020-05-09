#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    for(auto &e : s){
        if(e < '0' || e > '9'){
            cout << "error" << endl;
            return 0;
        }
    }
    cout << stoi(s) * 2 << endl;
    return 0;
}