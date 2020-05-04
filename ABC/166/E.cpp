#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
vector<ll> v;
unordered_map<ll,ll> um;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        v.push_back(a-i);
        if(um.count(a-i) == 0) um[a-i] = 1;
        else um[a-i] = um[a-i] + 1;
    }
    ll count = 0;
    for(int i=0;i<N-1;i++){
        ll s = 0 - i * 2 - v[i];
        if(um.count(s) == 0){
            um[v[i]] = um[v[i]] - 1;
            continue;
        }
        if(um[s] <= 0){
            um[v[i]] = um[v[i]] - 1;
            continue;
        }
        count += um[s];
        um[v[i]] = um[v[i]] - 1;
    }
    cout << count << endl;
    return 0;
}