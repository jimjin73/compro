#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
ll A[10001];

int main(){
    cin >> N >> M;
    for(int i=0;i<M;i++) cin >> A[i];
    ll sum = 0;
    for(int i=0;i<M;i++) sum += A[i];
    if(sum > N) cout << -1 << endl;
    else cout << N-sum << endl;
    return 0;
}