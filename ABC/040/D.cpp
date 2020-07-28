#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> Q;
typedef pair<Q,ll> R;

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

ll N,M,O;
vector<Q> V;
vector<P> W;
vector<R> Z;
ll INF = 1e18;

int main(){
    cin >> N >> M;
    UnionFind uf(N);
    for(int i=0;i<M;i++){
        ll a,b,y;
        cin >> a >> b >> y;
        V.push_back({y,{a,b}});
        Z.push_back({{y,{a,b}},0});
    }
    cin >> O;
    for(int i=0;i<O;i++){
        ll v,w;
        cin >> v >> w;
        W.push_back({v,w});
        Z.push_back({{w,{INF,v}},i});
    }
    sort(Z.rbegin(),Z.rend());
    vector<ll> ans(O);
    for(auto &e : Z){
        ll y = e.first.first;
        ll a = e.first.second.first;
        ll b = e.first.second.second;
        ll c = e.second;
        if(a != INF){
            uf.unite(a-1, b-1);
        }else{
            ans[c] = uf.nodes(uf.root(b-1));
        }
    }
    for(auto &e : ans) cout << e << endl;
    return 0;
}