#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
vector<P> v;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        ll x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    map<P,ll> m;
    for(int i=0;i<N;i++){
        set<P> s;
        for(int j=i+1;j<N;j++){
            s.insert({v[i].first-v[j].first,v[i].second-v[j].second});
        }
        for(auto &e : s) m[e]++;
    }
    ll max_v = 0;
    for(auto &e : m){
        ll t = e.second;
        max_v = max(t,max_v);
    }
    cout << N - max_v  << endl;
    return 0;
}