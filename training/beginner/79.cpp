#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M,Q;
ll c[600][600];
ll p[100000];
ll q[100000];

int main(){
    cin >> N >> M >> Q;
    for(int i=0;i<=N+1;i++){
        for(int j=0;j<=N+1;j++){
            c[i][j] = 0;
        }
    }
    for(int i=0;i<M;i++){
        ll a,b;
        cin >> a >> b;
        c[a][b]++;
    }
    for(int i=0;i<Q;i++) cin >> p[i] >> q[i];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            c[i][j] += c[i][j-1] + c[i-1][j] - c[i-1][j-1];
        }
    }
    for(int i=0;i<Q;i++){
        cout << c[q[i]][q[i]] - c[q[i]][p[i]-1] - c[p[i]-1][q[i]] + c[p[i]-1][p[i]-1] << endl;;
    }
    return 0;
}