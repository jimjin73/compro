#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,M,S,T;
vector<vector<P>> X;
vector<vector<P>> Y;
ll INF = 1e18;

int main(){
    cin >> N >> M >> S >> T;
    S--, T--;
    X.resize(N);
    Y.resize(N);
    for(int i=0;i<M;i++){
        ll u,v,a,b;
        cin >> u >> v >> a >> b;
        X[u-1].push_back({v-1,a});
        X[v-1].push_back({u-1,a});
        Y[u-1].push_back({v-1,b});
        Y[v-1].push_back({u-1,b});
    }
    vector<ll> x(N,INF);
    vector<ll> y(N,INF);
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,S});
    while(!pq.empty()){
        auto t = pq.top();
        ll c = t.first;
        ll n = t.second;
        pq.pop();
        if(x[n] != INF) continue;
        x[n] = c;
        for(auto &e : X[n]){
            if(x[e.first] != INF) continue;
            pq.push({e.second + c, e.first});
        }
    }
    pq.push({0,T});
    while(!pq.empty()){
        auto t = pq.top();
        ll c = t.first;
        ll n = t.second;
        pq.pop();
        if(y[n] != INF) continue;
        y[n] = c;
        for(auto &e : Y[n]){
            if(y[e.first] != INF) continue;
            pq.push({e.second + c, e.first});
        }
    }
    vector<ll> ans;
    ans.push_back(-1);
    for(int i=0;i<N;i++){
        ll tmp = 1e15 - x[N-i-1] - y[N-i-1];
        ans.push_back(max(ans.back(),tmp));
    }
    for(int i=0;i<N;i++){
        cout << ans[N-i] << endl;
    }
    return 0;
}