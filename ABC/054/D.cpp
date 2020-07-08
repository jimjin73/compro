#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,Ma,Mb;
ll A[50], B[50], C[50];

ll cost[450][450];
ll INF = 1e18;

int main(){
    cin >> N >> Ma >> Mb;
    for(int i=0;i<N;i++) cin >> A[i] >> B[i] >> C[i];
    for(int i=0;i<=400;i++){
        for(int j=0;j<=400;j++){
            cost[i][j] = INF;
        }
    }
    cost[0][0] = 0;
    for(int i=0;i<N;i++){
        for(int a=400;a>=0;a--){
            for(int b=400;b>=0;b--){
                if(cost[a][b] == INF) continue;
                cost[a+A[i]][b+B[i]] = min(cost[a+A[i]][b+B[i]], cost[a][b] + C[i]);
            }
        }
    }
    ll ans = INF;
    for(int n=1;n*Ma<=400 && n*Mb<=400;n++){
        ans = min(ans, cost[n*Ma][n*Mb]);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}