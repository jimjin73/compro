#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
ll d[20][20];
ll thr[20][20];
ll dp_d[16][1<<16];
ll dp_c[16][1<<16];

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            d[i][j] = thr[i][j] = -1;
        }
    }
    for(int i=0;i<M;i++){
        ll s,t,x,y;
        cin >> s >> t >> x >> y;
        d[s-1][t-1] = d[t-1][s-1] = x;
        thr[s-1][t-1] = thr[t-1][s-1] = y;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<(1<<N);j++){
            dp_d[i][j] = 1e18;
            dp_c[i][j] = 0;
        }
    }
    dp_d[0][0] = 0;
    dp_c[0][0] = 1;
    for(int b=0;b<N;b++){
        for(int i=0;i<N;i++){
            for(int j=0;j<(1<<N);j++){
                bitset<16> bt(j);
                if(bt.count() != b) continue;
                if(dp_c[i][j] == 0) continue;
                for(int k=0;k<N;k++){
                    if(i==k) continue;
                    if(j == (j|(1<<k))) continue;
                    if(d[i][k] == -1) continue;
                    if(dp_d[i][j] + d[i][k] > thr[i][k]) continue;
                    ll dist = dp_d[i][j] + d[i][k];
                    if(dist < dp_d[k][j|(1<<k)]){
                        dp_d[k][j|(1<<k)] = dist;
                        dp_c[k][j|(1<<k)] = dp_c[i][j];
                    }else if(dist == dp_d[k][j|(1<<k)]){
                        dp_c[k][j|(1<<k)] += dp_c[i][j];
                    }
                }
            }
        }
    }
    if(dp_c[0][(1<<N)-1] ==  0 || dp_d[0][(1<<N)-1] == 1e18) cout << "IMPOSSIBLE" << endl;
    else cout << dp_d[0][(1<<N)-1] << " " << dp_c[0][(1<<N)-1] << endl;
    return 0;
}