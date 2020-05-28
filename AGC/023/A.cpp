#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
ll A[200000];

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=1;i<N;i++) A[i] += A[i-1];
    unordered_map<ll,ll> um;
    um[0]++;
    for(int i=0;i<N;i++) um[A[i]]++;
    ll ans = 0;
    for(auto &e : um){
        ll c = e.second;
        ans += c * (c-1) / 2;
    }
    cout << ans << endl;
    return 0;
}