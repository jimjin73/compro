#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
string s;
ll dp[1000005][2];

int main(){
    cin >> s;
    reverse(s.begin(),s.end());
    s += '0';
    N = s.size();
    for(int i=0;i<=N;i++){
        for(int j=0;j<2;j++){
            dp[i][j] = 1e15;
        }
    }
    dp[0][0] = 0;
    for(int i=0;i<N;i++){
        ll n = s[i] - '0';
        for(int j=0;j<2;j++){
            for(int k=0;k<10;k++){
                ll a = k;
                if(j==1) a--;
                if(a - n < 0){
                    dp[i+1][1] = min(dp[i+1][1], dp[i][j] + k + (a-n+10));
                }else{
                    dp[i+1][0] = min(dp[i+1][0], dp[i][j] + k + (a-n));
                }
            }
        }
    }
    cout << dp[N][0] << endl;
    return 0;
}