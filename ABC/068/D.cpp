#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll K;
    cin >> K;
    ll a = K / 50;
    ll b = K % 50;
    bool f = false;
    cout << 50 << endl;
    for(int i=0;i<51;i++){
        if(i == 50-b) continue;
        if(f) cout << " ";
        cout << a + i;
        f = true;
    }
    cout << endl;   
    return 0;
}