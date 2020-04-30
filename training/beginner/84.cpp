#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[5000][5000];
ll N,M;

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            dp[i][j] = -1;
        }
    }
    for(int i=0;i<M;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        dp[a-1][b-1] = c;
    }
    ll count = 0;
    if(dp[0][0] > 0) count++;
    for(int i=1;i<N;i++){
        for(int j=0;j<=i;j++){
            ll l,r;
            l = r = -1;
            if(j != 0) l = dp[i-1][j-1]-1;
            if(j != i) r = dp[i-1][j]-1;
            dp[i][j] = max(dp[i][j], l);
            dp[i][j] = max(dp[i][j], r);
            if(dp[i][j] >= 0) count++;
        }
    }
    cout << count << endl;
    return 0;
}