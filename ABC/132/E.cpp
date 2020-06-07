#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,M;
ll S,T;
vector<vector<ll>> G;
ll dist[300000];

int main(){
    cin >> N >> M;
    G.resize(3*N);
    for(int i=0;i<M;i++){
        ll a,b;
        cin >> a >> b;
        a--,b--;
        for(int j=0;j<3;j++){
            G[N*j+a].push_back(N*((j+1)%3)+b);
        }
    }
    for(int i=0;i<3*N;i++) dist[i] = 1e15;
    cin >> S >> T;
    S--, T--;
    dist[S] = 1;
    queue<ll> q;
    q.push(S);
    while(!q.empty() && dist[T] == 1e15){
        ll n = q.front();
        q.pop();
        for(auto &e : G[n]){
            if(dist[e] != 1e15) continue;
            dist[e] = dist[n] + 1;
            q.push(e);
        }
    }
    if(dist[T] == 1e15) cout << -1 << endl;
    else cout << dist[T] / 3 << endl;
    return 0;
}