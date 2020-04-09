#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll mod = 10000;
ll N,K;
ll dp[110][6];
unordered_map<ll,ll> um;

int main(){
    cin >> N >> K;
    ll a,b;
    for(int i=0;i<K;i++){
        cin >> a >> b;
        um[a-1] = b-1;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<6;j++){
            dp[i][j] = 0;
        }
    }
    if(um.count(0) == 0){
        for(int i=0;i<3;i++) dp[0][i] = 1;
    }else{
        dp[0][um[0]] = 1;
    }
    for(int i=1;i<N;i++){   
        if(um.count(i) == 0){
            for(int j=0;j<3;j++){
                for(int k=0;k<6;k++){
                    if(j==k || j+3==k) continue;
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= mod;
                }
            }
            for(int j=3;j<6;j++){
                dp[i][j] += dp[i-1][j-3];
                dp[i][j] %= mod;
            }
        }else{
            int t = um[i];
            for(int j=0;j<3;j++){
                if(t != j) continue;
                for(int k=0;k<6;k++){
                    if(j==k || j+3==k) continue;
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= mod;
                }
            }
            for(int j=3;j<6;j++){
                if(t + 3 != j) continue;
                dp[i][j] += dp[i-1][j-3];
                dp[i][j] %= mod;
            }
        }
    }
    ll sum = 0;
    for(int i=0;i<6;i++) sum += dp[N-1][i];
    cout << sum % 10000 << endl;
    return 0;
}