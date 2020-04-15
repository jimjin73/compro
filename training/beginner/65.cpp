#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M,K;
unordered_map<ll,ll> um[100001];
ll cost[100001];
vector<ll> v;
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
ll INF = 1e12;

int main(){
    cin >> N >> M >> K;
    for(int i=0;i<M;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        um[a-1][b-1] = c;
        um[b-1][a-1] = c;
    }
    for(int i=0;i<N;i++) cost[i] = INF;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        pair<ll,ll> p = pq.top();
        pq.pop();
        ll c = p.first;
        ll n = p.second;
        if(cost[n] != INF) continue;
        cost[n] = c;
        if(c > 0) v.push_back(c);
        for(auto &e : um[n]){
            ll ep = e.first;
            ll l = e.second;
            if(cost[ep] != INF) continue;
            pq.push(make_pair(l,ep));
        }
    }
    sort(v.begin(),v.end());
    ll sum = 0;
    for(int i=0;i<(v.size()-K+1);i++) sum += v[i];
    cout << sum << endl;
    return 0;
}