#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

unordered_map<ll,ll> um;
ll N,Q;
vector<ll> v;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        ll tmp;
        cin >> tmp;
        um[tmp]++;
    }
    ll sum = 0;
    for(auto &e : um){
        sum += e.first * e.second;
    }
    cin >> Q;
    for(int i=0;i<Q;i++){
        ll b,c;
        cin >> b >> c;
        if(um.find(b) != um.end()){
            ll tmp = um[b];
            um[b] = 0;
            um[c] += tmp;
            sum += (c-b) * tmp;
        }
        v.push_back(sum);
    }
    for(auto &e : v) cout << e << endl;
    return 0;
}