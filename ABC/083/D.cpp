#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

string s;

bool check(ll l){
    if(l%2 == 1){
        return s[l/2] == '1';
    }
    return s[l/2] == '1' && s[l/2-1] == '1';
}

void rev(ll l){
    for(int i=0;i<l;i++){
        if(s[i] == '0') s[i] = '1';
        else s[i] = '0';
    }
}

int main(){
    cin >> s;
    ll L = s.size();
    ll K = 1e8;
    if(check(L)) rev(L);
    bool f = true;
    for(int i=0;i<L;i++) f &= (s[i] == '0');
    if(f){
        cout << L << endl;
        return 0;
    }
    for(int i=0;i<L;i++){
        if(s[i] == '0') continue;
        K = min(K, max((ll)i, (ll)L-i-1));
    }
    cout << K << endl;
    return 0;
}