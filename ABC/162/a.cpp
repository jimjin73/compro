#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;

int main(){
    cin >> s;
    for(int i=0;i<3;i++){
        if(s[i] == '7'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}