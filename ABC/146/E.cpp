#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,K;
ll A[200001];
unordered_map<ll,vector<ll>> um;

ll sh(vector<ll> &v){
    if(v.size() <= 1) return 0;
    ll sp = 0;
    ll ep = 1;
    ll ans = 0;
    while(ep < v.size()){
        while(v[ep] - v[sp] >= K) sp++;
        ans += (ep - sp);
        ep++;
    }
    return ans;
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> A[i];
    A[0] += K-1;
    A[0] %= K;
    for(int i=1;i<N;i++){
        A[i] += A[i-1] + K - 1;
        A[i] %= K;
    }
    um[0].push_back(-1);
    for(int i=0;i<N;i++){
        um[A[i]].push_back(i);
    }
    ll count = 0;
    for(auto p=um.begin(); p!=um.end(); p++){
        ll k = p->first;
        vector<ll> v = p->second;
        count += sh(v);
    }
    cout << count << endl;
    return 0;
}