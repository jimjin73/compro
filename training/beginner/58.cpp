#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M,K,S;
ll P,Q;
unordered_set<ll> us[100010];
ll d[100010];
vector<ll> z;
queue<ll> q;
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
ll cost[100010];

int main(){
    cin >> N >> M >> K >> S;
    cin >> P >> Q;
    ll s,t;
    for(int i=0;i<N;i++) d[i] = cost[i] = 1e12;
    for(int i=0;i<K;i++){
        cin >> t;
        z.push_back(t-1);
        d[t-1] = 0;
        q.push(t-1);
    }
    for(int i=0;i<M;i++){
        cin >> s >> t;
        us[s-1].insert(t-1);
        us[t-1].insert(s-1);
    }
    while(!q.empty()){
        s = q.front();
        q.pop();
        if(d[s] == S) continue;
        for(const auto& e : us[s]){
            if(d[e] != 1e12) continue;
            d[e] = d[s] + 1;
            q.push(e);
        }
    }
    cost[0] = 0;
    for(int i=0;i<N;i++){
        if(d[i] == 0) continue;
        if(us[0].find(i) == us[0].end()) continue;
        pq.push(make_pair(0, i));
    }
    while(true){
        pair<ll,ll> p = pq.top();
        pq.pop();
        ll c = p.first;
        ll n = p.second;
        if(cost[n] != 1e12) continue;
        cost[n] = c;
        if(n == N-1){
            cout << c << endl;
            break;
        }
        ll cc = 0;
        if(d[n] == 1e12) cc = P;
        else cc = Q;
        for(const auto&e : us[n]){
            if(d[e] == 0) continue;
            if(cost[e] != 1e12) continue;
            pq.push(make_pair(c + cc, e));
        }
    }
    return 0;
}