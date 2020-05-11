#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct UnionFind{
    vector<ll> par;
    vector<ll> chs;
    vector<ll> d;
    UnionFind(ll N){
        par.resize(N);
        chs.resize(N);
        d.resize(N);
        for(int i=0;i<N;i++) par[i] = i;
        for(int i=0;i<N;i++) chs[i] = 1;
        for(int i=0;i<N;i++) d[i] = 1;
    }
    ll root(ll n){
        if(par[n] == n) return n;
        return root(par[n]);
    }
    void unite(ll a, ll b){
        ll ra = root(a);
        ll rb = root(b);
        if(ra == rb) return;
        if(d[ra] >= d[rb]){
            par[rb] = ra;
            chs[ra] += chs[rb];
            d[ra] = max(d[ra], d[rb] + 1);
        }else{
            par[ra] = rb;
            chs[rb] += chs[ra];
        }
    }
    bool isSame(ll a,ll b){
        return root(a) == root(b);
    }
    ll nodes(ll n){
        return chs[root(n)];
    }
};

ll N,M,K;
ll f[100000];

int main(){
    cin >> N >> M >> K;
    UnionFind uf(N);
    for(int i=0;i<M;i++){
        ll a,b;
        cin >> a >> b;
        uf.unite(a-1,b-1);
        f[a-1]++;
        f[b-1]++;
    }
    for(int i=0;i<K;i++){
        ll a,b;
        cin >> a >> b;
        if(uf.root(a-1) == uf.root(b-1)){
            f[a-1]++;
            f[b-1]++;
        }
    }
    for(int i=0;i<N;i++){
        cout << uf.chs[uf.root(i)] - f[i] - 1;
        if(i != N-1) cout << " ";
    }
    cout << endl;
    return 0;
}