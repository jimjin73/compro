#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> G;
ll dist[1002];
ll bef[1002];
string ss,es;
ll N,L;
string s[1002];
ll sp,ep;
bool f[1000];

ll diff(string &a, string &b){
    ll d = 0;
    for(int i=0;i<L;i++){
        if(a[i] != b[i]) d++;
    }
    return d;
}

int main(){
    cin >> s[0] >> s[1];
    cin >> N;
    G.resize(N+2);
    for(int i=0;i<N;i++) cin >> s[i+2];
    L = s[0].size();
    for(int i=0;i<N+2;i++){
        f[i] = true;
        for(int j=0;j<i;j++){
            if(!f[j]) continue;
            if(diff(s[i],s[j]) > 1) continue;
            G[i].push_back(j);
            G[j].push_back(i);
        }
    }
    sp = 0;
    ep = 1;
    for(int i=0;i<N+2;i++) dist[i] = bef[i] = -1;
    dist[sp] = 0;
    queue<ll> q;
    q.push(sp);
    while(dist[ep] == -1 && !q.empty()){
        ll p = q.front();
        q.pop();
        for(auto &e : G[p]){
            if(dist[e] != -1) continue;
            dist[e] = dist[p] + 1;
            bef[e] = p;
            q.push(e);
        }
    }
    if(dist[ep] == -1){
        cout << -1 << endl;
        return 0;
    }
    deque<ll> v;
    v.push_front(ep);
    while(true){
        ll p = bef[v[0]];
        if(p == -1) break;
        v.push_front(p);
    }
    cout << v.size() - 2 << endl;
    for(auto &e : v) cout << s[e] << endl;
    return 0;
}