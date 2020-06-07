#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,C;
ll X[100000];
ll V[100000];
ll R[100000];
ll L[100000];

int main(){
    cin >> N >> C;
    for(int i=0;i<N;i++) cin >> X[i] >> V[i];
    ll c = 0;
    for(int i=0;i<N;i++){
        c += V[i];
        R[i] = max((ll)0, c-X[i]);
        if(i > 0) R[i] = max(R[i], R[i-1]);
    }
    c = 0;
    for(int i=N-1;i>=0;i--){
        c += V[i];
        L[i] = max((ll)0,c-(C-X[i]));
        if(i < N-1) L[i] = max(L[i], L[i+1]);
    }
    ll max_c = max(R[N-1],L[0]);
    for(int i=0;i<N-1;i++){
        ll m = R[i] + L[i+1] - min(X[i], C-X[i+1]);
        max_c = max(max_c, m);
    }
    cout << max_c << endl;
    return 0;
}