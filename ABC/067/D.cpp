#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

vector<vector<ll>> G;
ll N;
ll par[100000];
ll d[100000];
ll chs[100000];

void bfs(ll n){
    for(auto &e : G[n]){
        if(e == par[n]) continue;
        par[e] = n;
        d[e] = d[n] + 1;
        bfs(e);
        chs[n] += chs[e];
    }
    chs[n]++;
}

int main(){
    cin >> N;
    G.resize(N);
    for(int i=0;i<N-1;i++){
        ll a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    par[0] = -1;
    d[0] = 1;
    bfs(0);
    ll D = d[N-1];
    ll p = N-1;
    for(int i=0;i<(D/2)-1;i++) p = par[p];
    ll s = chs[p];
    ll f = N - s;
    if(f > s) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
    return 0;
}