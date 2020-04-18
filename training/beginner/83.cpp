#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll M,N;
ll P[100010];
ll imos[100010];
ll A[100010], B[100010], C[100010];

int main(){
    cin >> N >> M;
    for(int i=0;i<=N;i++) imos[i] = 0;
    for(int i=0;i<M;i++) cin >> P[i];
    for(int i=0;i<N-1;i++) cin >> A[i] >> B[i] >> C[i];
    for(int i=1;i<M;i++){
        imos[min(P[i-1],P[i])]++;
        imos[max(P[i-1],P[i])]--;
    }
    for(int i=1;i<=N;i++) imos[i] += imos[i-1];
    ll sum = 0;
    for(int i=1;i<N;i++) sum += min(imos[i] * A[i-1], imos[i] * B[i-1] + C[i-1]);
    cout << sum << endl;
    return 0;
}