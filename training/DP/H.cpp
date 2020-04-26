#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll H,W;
string s[1000];
ll m[1000][1000];
ll MOD = 1e9+7;

int main(){
    cin >> H >> W;
    for(int i=0;i<H;i++) cin >> s[i];
    m[0][0] = 1;
    for(int i=1;i<H;i++){
        if(s[i][0] == '.') m[i][0] = m[i-1][0];
        else m[i][0] = 0;
    }
    for(int i=1;i<W;i++){
        if(s[0][i] == '.') m[0][i] = m[0][i-1];
        else m[0][i] = 0;
    }
    for(int i=1;i<H;i++){
        for(int j=1;j<W;j++){
            if(s[i][j] == '#'){
                m[i][j] = 0;
                continue;
            }
            m[i][j] = m[i-1][j] + m[i][j-1];
            m[i][j] %= MOD;
        }
    }
    cout << m[H-1][W-1] << endl;
    return 0;
}