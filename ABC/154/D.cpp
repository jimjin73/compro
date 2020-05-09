#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,K;
ll P[200000];

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> P[i];
    for(int i=1;i<N;i++) P[i] += P[i-1];
    ll max_p = P[K-1];
    for(int i=K;i<N;i++){
        max_p = max(max_p, P[i] - P[i-K]);
    }
    cout << fixed << setprecision(15) << ((double)max_p+K)/2.0 << endl;
    return 0;
}