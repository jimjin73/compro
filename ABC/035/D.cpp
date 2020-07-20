#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,M,T;
ll A[100000];
vector<vector<P>> F;
vector<vector<P>> B;

ll fd[100000];
ll bd[100000];
ll INF = 1e18;

int main(){
    cin >> N >> M >> T;
    F.resize(N);
    B.resize(N);
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<M;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        F[a-1].push_back({b-1,c});
        B[b-1].push_back({a-1,c});
    }
    for(int i=0;i<N;i++) fd[i] = bd[i] = INF;
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        ll c = t.first;
        ll n = t.second;
        if(fd[n] != INF) continue;
        fd[n] = c;
        for(auto &e : F[n]){
            ll cc = e.second;
            ll nn = e.first;
            if(fd[nn] != INF) continue;
            pq.push({c+cc, nn});
        }
    }
    pq.push({0,0});
    while(!pq.empty()){
        auto t = pq.top();
        pq.pop();
        ll c = t.first;
        ll n = t.second;
        if(bd[n] != INF) continue;
        bd[n] = c;
        for(auto &e : B[n]){
            ll cc = e.second;
            ll nn = e.first;
            if(bd[nn] != INF) continue;
            pq.push({c+cc, nn});
        }
    }
    ll ans = 0;
    for(int i=0;i<N;i++){
        if(T < fd[i] + bd[i]) continue;
        ans = max(ans,A[i] * (T-fd[i]-bd[i]));
    }
    cout << ans << endl;
    return 0;
}