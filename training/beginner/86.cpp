#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
ll a[100];
ll b[100];

struct UnionFind{
    vector<ll> par;
    vector<ll> chs;
    UnionFind(ll N){
        par.resize(N);
        chs.resize(N);
        for(int i=0;i<N;i++) par[i] = i;
        for(int i=0;i<N;i++) chs[i] = 1;
    }
    ll root(ll n){
        if(par[n] == n) return n;
        return root(par[n]);
    }
    void unite(ll a, ll b){
        ll ra = root(a);
        ll rb = root(b);
        if(ra == rb) return;
        if(chs[ra] >= chs[rb]){
            par[rb] = ra;
            chs[ra] = max(chs[ra], chs[rb] + 1);
        }else{
            par[ra] = rb;
        }
    }
    bool isSame(ll a,ll b){
        return root(a) == root(b);
    }
};

int main(){
    cin >> N >> M;
    for(int i=0;i<M;i++) cin >> a[i] >> b[i];
    for(int i=0;i<M;i++) a[i]--,b[i]--;
    ll sum = 0;
    for(int i=0;i<M;i++){
        UnionFind uf = UnionFind(N);
        for(int j=0;j<M;j++){
            if(i==j) continue;
            uf.unite(a[j], b[j]);
        }
        bool f = false;
        ll r = uf.root(0);
        for(int i=1;i<N;i++){
            if(r != uf.root(i)) f = true;
        }
        if(f) sum++;
    }
    cout << sum << endl;
    return 0;
}