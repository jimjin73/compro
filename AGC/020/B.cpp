#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll K;
vector<ll> v;

pair<ll,ll> update(ll s, ll e, ll t){
    ll ss = s % t;
    ss = s + ((t-ss)%t);
    ll ee = e % t;
    ee = e - ee;
    //cout << s << " " << e << " " << t << " " << ss << " " << ee << endl;
    if(ss > ee) return {-1,-1};
    if(ss < s || ss > e) return {-1,-1};
    if(ee < s || ee > e) return {-1,-1};
    return {ss,ee};
}

int main(){
    cin >> K;
    for(int i=0;i<K;i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    reverse(v.begin(),v.end());
    ll s,e;
    s = e = 2;
    for(int i=0;i<K;i++){
        auto p = update(s,e,v[i]);
        if(p.first == -1){
            cout << -1 << endl;
            return 0;
        }
        s = p.first;
        e = p.second + (v[i] - 1);
    }
    cout << s << " " << e << endl;
    return 0;
}