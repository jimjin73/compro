#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
ll A[100000];
ll M = 1e18;

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    bool f = false;
    for(int i=0;i<N;i++){
        if(A[i] == 0) f = true;
    }
    if(f){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for(int i=0;i<N;i++){
        if(M / A[i] < ans){
            cout << -1 << endl;
            return 0;
        }
        ans *= A[i];
        if(ans > M){
            cout << -1 << endl;
            return 0;
        }
        if(ans < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}