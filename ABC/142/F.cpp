#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> Q;

ll N,M;
vector<vector<ll>> G;
ll INF = 1e18;

int main(){
    cin >> N >> M;
    G.resize(N);
    for(int i=0;i<M;i++){
        ll a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
    }
    ll ans = INF;
    vector<ll> ans_vec;
    for(int i=0;i<N;i++){
        queue<Q> q;
        vector<P> dist(N,{INF,-1});
        for(auto &e : G[i]) q.push({e,{0,-1}});
        while(!q.empty() && dist[i].first == INF){
            auto e = q.front();
            q.pop();
            ll n = e.first;
            if(dist[n].first != INF) continue;
            dist[n] = e.second;
            for(auto &f : G[n]){
                if(dist[f].first != INF) continue;
                q.push({f,{e.second.second+1,n}});
            }
        }
        if(dist[i].first == INF) continue;
        vector<ll> tmp;
        ll p = i;
        while(p != -1){
            tmp.push_back(p);
            p = dist[p].second;
        }
        if(ans > tmp.size()){
            ans_vec = tmp;
            ans = tmp.size();
        }
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
        for(int i=ans-1;i>=0;i--) cout << ans_vec[i]+1 << endl;
    }
    return 0;
}