#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll F[11][11];

int main(){
    cin >> N;
    ll c = 0;
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            F[i][j] = 0;
        }
    }
    for(int i=1;i<=N;i++){
        string s = to_string(i);
        if(s[s.size()-1] == '0') continue;
        F[s[0]-'0'][s[s.size()-1]-'0']++;
    }
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            c += F[i][j] * F[j][i];
        }
    }
    cout << c << endl;
    return 0;
}