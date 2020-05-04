#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
ll a,b;
vector<vector<ll>> G;
ll dist[100];
ll INF = 1e15;
ll MOD = 1e9+7;
vector<vector<ll>> D;
ll dp[100];

int main(){
    cin >> N;
    cin >> a >> b;
    cin >> M;
    a--,b--;
    G.resize(N);
    for(int i=0;i<M;i++){
        ll x,y;
        cin >> x >> y;
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }
    for(int i=0;i<N;i++) dist[i] = INF;
    dist[a] = 0;
    queue<ll> q;
    q.push(a);
    while(dist[b] == INF){
        ll n = q.front();
        q.pop();
        for(auto &e : G[n]){
            if(dist[e] != INF) continue;
            dist[e] = dist[n] + 1;
            q.push(e);
        }
    }
    D.resize(dist[b] + 1);
    for(int i=0;i<N;i++){
        if(dist[i] > dist[b]) continue;
        D[dist[i]].push_back(i);
    }
    for(int i=0;i<N;i++) dp[i] = 0;
    dp[a] = 1;
    for(int i=1;i<=dist[b];i++){
        for(auto &e : D[i]){
            for(auto &f : G[e]){
                if(dist[f] + 1 != dist[e]) continue;
                dp[e] += dp[f];
                dp[e] %= MOD;
            }
        }
    }
    cout << dp[b] << endl;
    return 0;
}