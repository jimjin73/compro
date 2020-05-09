#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,D,A;
vector<ll> X,H,P;
vector<pair<ll,ll>> v;

int main(){
    ll c = 0;
    cin >> N >> D >> A;
    for(int i=0;i<N;i++){
        ll x,h;
        cin >> x >> h;
        v.push_back(make_pair(x,h));
        P.push_back(0);
    }
    sort(v.begin(),v.end());
    for(auto &e : v){
        X.push_back(e.first);
        H.push_back(e.second);
    }
    ll t = H[0] / A;
    if(H[0]%A != 0) t++;
    c += t;
    t *= A;
    P[0] -= t;
    ll ind = upper_bound(X.begin(),X.end(),X[0]+2*D) - X.begin();
    if(ind < N) P[ind] += t;
    for(int i=1;i<N;i++){
        P[i] += P[i-1];
        if(H[i] + P[i] <= 0) continue;
        H[i] += P[i];
        t = H[i] / A;
        if(H[i]%A != 0) t++;
        c += t;
        t *= A;
        P[i] -= t;
        ll ind = upper_bound(X.begin(),X.end(),X[i]+2*D) - X.begin();
        if(ind < N) P[ind] += t;
    }
    cout << c << endl;
    return 0;
}