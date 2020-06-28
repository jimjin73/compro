#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
ll A[200000];
ll max_n[200000];

int main(){
    cin >> N;
    for(int i=0;i<=N;i++) cin >> A[i];
    max_n[0] = 1;
    for(int i=1;i<=N;i++){
        max_n[i] = (max_n[i-1] - A[i-1]) * 2;
        if(max_n[i] > 1e18){
            max_n[i] = 1e18;
        }
    }
    for(int i=0;i<=N;i++){
        if(max_n[i] < A[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    ll n = 0;
    ll ans = 0;
    for(int i=N;i>=0;i--){
        n += A[i];
        ans += min(max_n[i], n);
    }
    cout << ans << endl;
    return 0;
}