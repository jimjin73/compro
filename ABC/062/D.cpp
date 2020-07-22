#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
ll A[300000];
ll f[100010];
ll b[100010];

int main(){
    cin >> N;
    for(int i=0;i<3*N;i++) cin >> A[i];
    priority_queue<ll,vector<ll>,greater<ll>> pqf;
    f[0] = 0;
    for(int i=0;i<N;i++){
        pqf.push(A[i]);
        f[0] += A[i];
    }
    for(int i=0;i<N;i++){
        ll m = pqf.top();
        pqf.pop();
        if(m < A[i+N]){
            pqf.push(A[i+N]);
            f[i+1] = f[i] + A[i+N] - m;
        }else{
            pqf.push(m);
            f[i+1] = f[i];
        }
    }
    priority_queue<ll> pqb;
    b[0] = 0;
    for(int i=2*N;i<3*N;i++){
        pqb.push(A[i]);
        b[0] += A[i];
    }
    for(int i=0;i<N;i++){
        ll m = pqb.top();
        pqb.pop();
        if(m > A[2*N-1-i]){
            pqb.push(A[2*N-1-i]);
            b[i+1] = b[i] + A[2*N-1-i] - m;
        }else{
            pqb.push(m);
            b[i+1] = b[i];
        }
    } 
    ll ans = -1e18;
    for(int i=0;i<=N;i++) ans = max(ans, f[i] - b[N-i]);
    cout << ans << endl;
    return 0;
}