#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[150][4][2];

int main(){
    string s;
    ll K;
    cin >> s;
    cin >> K;
    dp[0][0][0] = 1;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<=K;j++){
            for(int k=0;k<2;k++){
                ll sd = s[i] - '0';
                for(int d=0;d<10;d++){
                    int dk = k;
                    int dj = j;
                    if(d != 0) dj++;
                    if(dj > K) continue;
                    if(k==0){
                        if(sd < d) continue;
                        if(sd > d) dk++;
                    }
                    dp[i+1][dj][dk] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[s.size()][K][0] + dp[s.size()][K][1] << endl;
    return 0;
}