#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
vector<vector<int>> G;
priority_queue<int,vector<int>,greater<int>> pq;
bool memo[100000];

int main(){
    cin >> N;
    G.resize(N);
    for(int i=0;i<N-1;i++){
        int a,b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    pq.push(0);
    while(!pq.empty()){
        int n = pq.top();
        pq.pop();
        if(memo[n]) continue;
        if(n != 0) cout << " ";
        cout << n+1;
        memo[n] = true;
        for(auto &e : G[n]){
            if(memo[e]) continue;
            pq.push(e);
        }
    }
    cout << endl;
    return 0;
}