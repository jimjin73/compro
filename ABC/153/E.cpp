#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll H,N;
ll A[1000];
ll B[1000];
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
ll cost[10001];

int main(){
    cin >> H >> N;
    for(int i=0;i<N;i++) cin >> A[i] >> B[i];
    for(int i=0;i<=H;i++) cost[i] = 1e15;
    pq.push(make_pair(0,0));
    while(true){
        pair<ll,ll> p = pq.top();
        pq.pop();
        ll c = p.first;
        ll d = p.second;
        if(d >= H){
            cout << c << endl;
            break;
        }
        if(cost[d] != 1e15) continue;
        cost[d] = c;
        for(int i=0;i<N;i++){
            if(d+B[i] <= H && cost[d+B[i]] != 1e15) continue;
            pq.push(make_pair(c + B[i],d + A[i]));
        }
    }
    return 0;
}