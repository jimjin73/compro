#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,K;
unordered_set<ll> l[5010];
ll C[5010];
ll R[5010];
ll cost[5010];
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
ll memo[5050];

vector<ll> cand(ll n){
    vector<ll> ans;
    for(int i=0;i<N;i++) memo[i] = 1e12;
    queue<ll> q;
    q.push(n);
    memo[n] = 0;
    while(!q.empty()){
        ll t = q.front();
        q.pop();
        if(memo[t] == R[n]) continue;
        for(auto &e:l[t]){
            if(memo[e] != 1e12) continue;
            memo[e] = memo[t] + 1;
            q.push(e);
        }
    }
    for(int i=0;i<N;i++)  if(memo[i] != 1e12) ans.push_back(i);
    return ans;
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> C[i] >> R[i];
        cost[i] = 1e12;
    }
    for(int i=0;i<K;i++){
        ll a,b;
        cin >> a >> b;
        l[a-1].insert(b-1);
        l[b-1].insert(a-1);
    }
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        pair<ll,ll> p = pq.top();
        pq.pop();
        ll c = p.first;
        ll n = p.second;
        if(n == N-1){
            cout << c << endl;
            break;
        }
        if(cost[n] != 1e12) continue;
        cost[n] = c;
        vector<ll> v = cand(n);
        for(auto &e : v){
            if(cost[e] != 1e12) continue;
            pq.push(make_pair(cost[n] + C[n], e));
        }
    }
    return 0;
}