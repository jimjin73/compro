#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
vector<vector<ll>> G;
ll p[100000];

int main(){
    cin >> N >> M;
    G.resize(N);
    for(int i=0;i<M;i++){
        ll a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    for(int i=0;i<N;i++) p[i] = -1;
    p[0] = 0;
    queue<ll> q;
    q.push(0);
    while(!q.empty()){
        ll a = q.front();
        q.pop();
        for(auto &e : G[a]){
            if(p[e] != -1) continue;
            p[e] = a;
            q.push(e);
        }
    }
    cout << "Yes" << endl;
    for(int i=1;i<N;i++){
        cout << p[i]+1 << endl;
    }
    return 0;
}