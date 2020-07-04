#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
vector<vector<ll>> G;
vector<ll> c;
ll idx;
ll d[10001];

ll bfs(ll n, ll p){
    ll ret = 0;
    d[n] = c[idx];
    idx++;
    if(p != -1) ret += d[n];
    for(auto &e : G[n]){
        if(e==p) continue;
        ret += bfs(e,n);
    }
    return ret;
}

int main(){
    cin >> N;
    G.resize(N);
    c.resize(N);
    for(int i=0;i<N-1;i++){
        ll a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    for(int i=0;i<N;i++) cin >> c[i];
    sort(c.rbegin(),c.rend());
    idx = 0;
    cout << bfs(0,-1) << endl;
    for(int i=0;i<N;i++){
        cout << d[i];
        if(i < N-1) cout << " ";
    }
    cout << endl;
    return 0;
}