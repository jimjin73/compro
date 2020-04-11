#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[2050];
ll N;
ll dp[2050][2050];

ll rec(ll x, ll y){
    if(dp[x][y] != -1) return dp[x][y];
    if(x == y) return dp[x][y] = 0;
    if((x+N-y)%N == 1) return dp[x][y] = 0;
    if(A[(x-1+N)%N] > A[y]){
        return dp[x][y] = max(rec((x-1+N)%N, (y+1)%N) + A[y], rec((x-2+N)%N, y) + A[(x-2+N)%N]);
    }else{
        return dp[x][y] = max(rec((x-1+N)%N, (y+1)%N) + A[(x-1+N)%N], rec(x%N, (y+2)%N) + A[(y+1)%N]);
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = -1;
        }
    }
    ll max_p = -1e9;
    for(int i=0;i<N;i++){
        max_p = max(max_p,rec(i,(i+1)%N) + A[i]);
    }
    cout << max_p << endl;
    return 0;
}