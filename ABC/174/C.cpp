#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

bool b[1000010];

int main(){
    ll K;
    ll t = 7;
    ll c = 1;
    cin >> K;
    t = t % K;
    while(true){
        if(t == 0) break;
        if(b[t]){
            cout << -1 << endl;
            return 0;
        }
        b[t] = true;
        t *= 10;
        t += 7;
        t %= K;
        c++;
    }
    cout << c << endl;
    return 0;
}