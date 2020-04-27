#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll a[3000];
ll dp[3001][3001];

ll taro(ll sp, ll ep);
ll jiro(ll sp, ll ep);

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> a[i];
    for(int i=0;i<N;i++){
        for(int j=0;j<=N;j++){
            dp[i][j] = -1;
        }
    }
    ll p = taro(0,N);
    ll sum = 0;
    for(int i=0;i<N;i++) sum += a[i];
    ll q = sum - p;
    cout << p - q << endl; 
    return 0;
}

ll taro(ll sp, ll ep){
    if(dp[sp][ep] != -1) return dp[sp][ep];
    if(sp == ep-1) return dp[sp][ep] = a[sp];
    if(sp == ep-2) return dp[sp][ep] = max(a[sp],a[sp+1]);
    return dp[sp][ep] = max(jiro(sp+1,ep) + a[sp], jiro(sp,ep-1) + a[ep-1]);
}

ll jiro(ll sp, ll ep){
    if(dp[sp][ep] != -1) return dp[sp][ep];
    if(sp == ep-1) return dp[sp][ep] = 0;
    if(sp == ep-2) return dp[sp][ep] = min(a[sp],a[sp+1]);
    return dp[sp][ep] = min(taro(sp+1,ep), taro(sp,ep-1));
}