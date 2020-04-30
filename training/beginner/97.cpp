#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
ll a[100000];

ll count(ll n){
    bitset<64> bt(n);
    for(int i=0;i<N;i++){
        if(bt[i] == 1) return i;
    }
    return -1;
}

bool check(ll m){
    for(int i=1;i<N;i++){
        if(count(a[i]) != m) return true;
    }
    return false;
}

int main(){
    cin >> N >> M;
    ll l = 1;
    for(int i=0;i<N;i++) cin >> a[i];
    for(int i=0;i<N;i++){
        if(a[i] % 2 == 1){
            cout << 0 << endl;
            return 0;
        }
        a[i] /= 2;
    }
    ll b = count(a[0]);
    if(check(b)){
        cout << 0 << endl;
        return 0;
    }
    for(int i=1;i<N;i++){
        ll g = __gcd(a[i],a[i-1]);
        a[i] /= g;
        a[i] *= a[i-1];
    }
    cout << ((M / a[N-1]) + 1) / 2 << endl;
    return 0;
}