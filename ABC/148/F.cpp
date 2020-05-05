#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> G;
ll N;
ll A,T;
ll par[100000];
ll deep[100000];
ll len[100000];

void bfs(ll n, ll p){
    par[n] = p;
    if(G[n].size() == 1 && G[n][0] == p){
        deep[n] = 0;
        return;
    }
    ll d = 0;
    for(auto &e : G[n]){
        if(e==p) continue;
        len[e] = len[n]+1;
        bfs(e,n);
        d = max(d, deep[e]);
    }
    deep[n] = d + 1;
}

int main(){
    cin >> N >> T >> A;
    T--,A--;
    G.resize(N);
    for(int i=0;i<N-1;i++){
        ll a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    len[A] = 0;
    bfs(A,-1);

    /*
    for(int i=0;i<N;i++) cout << par[i] << " ";
    cout << endl;
    for(int i=0;i<N;i++) cout << deep[i] << " ";
    cout << endl;
    */
   
    ll max_d = (len[T]-1) / 2;

    //cout << max_d << endl;

    ll max_p = T;
    for(int i=0;i<max_d;i++) max_p = par[max_p];

    //cout << max_p << endl;

    ll c =  1 - (len[T] % 2);
    c += max_d + deep[max_p];
    cout << c << endl;
    return 0;
}