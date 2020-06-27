#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

vector<ll> A,B;
ll N,M,K;

int main(){
    cin >> N >> M >> K;
    A.push_back(0);
    B.push_back(0);
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0;i<M;i++){
        ll b;
        cin >> b;
        B.push_back(b);
    }
    for(int i=1;i<=N;i++) A[i] += A[i-1];
    for(int j=1;j<=M;j++) B[j] += B[j-1];
    ll ans = 0;
    for(int i=0;i<=N;i++){
        if(A[i] > K) break;
        ll t = upper_bound(B.begin(),B.end(),K-A[i]) - B.begin() - 1;
        ans = max(ans, t + i);
    }
    cout << ans << endl;
    return 0;
}