#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> Q;

ll N,M;
vector<vector<P>> G;
ll d[200000];

int main(){
    cin >> N >> M;
    G.resize(N);
    for(int i=1;i<N;i++) G[i].push_back({i-1,0});
    for(int i=0;i<M;i++){
        ll l,r,c;
        cin >> l >> r >> c;
        G[l-1].push_back({r-1,c});
    }
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,0});
    for(int i=0;i<N;i++) d[i] = -1;
    while(d[N-1] < 0 && !pq.empty()){
        P p = pq.top();
        pq.pop();
        ll n = p.second;
        ll c = p.first;
        if(d[n] >= 0) continue;
        d[n] = c;
        for(auto &e : G[n]){
            if(d[e.first] >= 0) continue;
            pq.push({d[n]+e.second,e.first});
        }
    }
    cout << d[N-1] << endl;
    return 0;
}