#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

/*
par   : 親ノード
chs   : 自分を根とする木のノード数
d     : 自分を根とする木の深さ
root  : 自分の属する木のrootを返す
unite : 二つの木をマージする
isSame: 二つのノードが同一の木に属するか判定する
nodes : 自身が属する木のノード数
*/

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