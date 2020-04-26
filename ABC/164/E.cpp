#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> G;
ll N,M,S;
ll A[50][50];
ll B[50][50];
ll C[50];
ll D[50];

priority_queue<pair<ll, pair<ll,ll>>, vector<pair<ll, pair<ll,ll>>>, greater<pair<ll, pair<ll,ll>>>> pq;
ll m[50][5010];

bool check(){
    for(int i=0;i<N;i++){
        if(m[i][0] == 1e15) return true;
    }
    return false;
}

int main(){
    cin >> N >> M >> S;
    G.resize(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            A[i][j] = B[i][j] = 1e15;
        }
    }
    for(int i=0;i<50;i++){
        for(int j=0;j<=5005;j++){
            m[i][j] = 1e15;
        }
    }
    for(int i=0;i<M;i++){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
        A[a-1][b-1] = A[b-1][a-1] = c;
        B[a-1][b-1] = B[b-1][a-1] = d;
    }
    for(int i=0;i<N;i++) cin >> C[i] >> D[i];
    pq.push(make_pair(0, make_pair(0,min(S,(ll)5000))));
    while(check()){
        pair<ll, pair<ll,ll>> p = pq.top();
        pq.pop();
        ll cost = p.first;
        ll n = p.second.first;
        ll s = p.second.second;
        if(m[n][s] == 1e15){
            for(int i=0;i<=s;i++){
                if(m[n][i] > cost) m[n][i] = cost;
            }
        }else{
            continue;
        }
        if(s < 5000) pq.push(make_pair(cost + D[n], make_pair(n,min(s+C[n],(ll)5000))));
        for(auto &e : G[n]){
            if(s >= A[n][e]) pq.push(make_pair(cost + B[n][e], make_pair(e,s-A[n][e])));
        }
    }
    for(int i=1;i<N;i++) cout << m[i][0] << endl;
    return 0;
}