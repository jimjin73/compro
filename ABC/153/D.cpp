#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll H;
unordered_map<ll,ll> um;


ll C(ll t){
    if(um.count(t) > 0) return um[t];
    if(t == 1) return um[1] = 1;
    return um[t] = C(t/2) * 2 + 1;
}

int main(){
    cin >> H;
    cout << C(H) << endl;
    return 0;
}