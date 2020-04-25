#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll N;
ll x[100001];
ll y[100001];
unordered_map<ll,ll> ums[100001];
ll z[100001];
priority_queue<pair<ll,ll>, vector<pair<ll,ll>> ,greater<pair<ll,ll>>> pq;

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> x[i] >> y[i];
    vector<pair<ll,ll>> vx,vy;
    for(int i=0;i<N;i++){
        vx.push_back(make_pair(x[i],i));
        vy.push_back(make_pair(y[i],i));
    }
    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    for(int i=1;i<N;i++){
        ums[vx[i].second][vx[i-1].second] = ums[vx[i-1].second][vx[i].second] = min(abs(x[vx[i].second] - x[vx[i-1].second]), abs(y[vx[i].second] - y[vx[i-1].second]));
        ums[vy[i].second][vy[i-1].second] = ums[vy[i-1].second][vy[i].second] = min(abs(y[vy[i].second] - y[vy[i-1].second]), abs(x[vy[i].second] - x[vy[i-1].second]));
    }
    for(int i=0;i<N;i++) z[i] = 0;
    z[0] = 1;
    for(auto p=ums[0].begin(); p!=ums[0].end(); p++){
        pq.push(make_pair(p->second, p->first));
    }
    ll cost = 0;
    while(!pq.empty()){
        pair<ll,ll> pp = pq.top();
        pq.pop();
        if(z[pp.second] != 0) continue;
        z[pp.second] = 1;
        cost += pp.first;
        for(auto p=ums[pp.second].begin(); p!=ums[pp.second].end(); p++){
            if(z[p->first] == 0) pq.push(make_pair(p->second, p->first));
        }
    }
    cout << cost << endl;
    return 0;
}