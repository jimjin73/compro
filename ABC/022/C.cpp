#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
ll m[300][300];
ll INF = 1e15;

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            m[i][j] = INF;
        }
    }
    for(int i=0;i<M;i++){
        ll u,v,l;
        cin >> u >> v >> l;
        m[u-1][v-1] = m[v-1][u-1] = l;
    }
    ll min_l = INF;
    for(int i=0;i<N;i++){
        if(m[0][i] == INF) continue;
        ll l = m[0][i];
        m[0][i] = m[i][0] = INF;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        pq.push(make_pair(l,i));
        vector<ll> v(N,INF);
        while(v[0] == INF && !pq.empty()){
            pair<ll,ll> p = pq.top();
            pq.pop();
            ll a = p.first;
            ll b = p.second;
            if(v[b] != INF) continue;
            v[b] = a;
            for(int j=0;j<N;j++){
                if(m[b][j] == INF) continue;
                if(v[j] != INF) continue;
                pq.push(make_pair(a + m[b][j],j));
            }
        }
        min_l = min(min_l, v[0]);
        m[0][i] = m[i][0] = l;
    }
    if(min_l == INF) cout << -1 << endl;
    else cout << min_l << endl;
    return 0;
}