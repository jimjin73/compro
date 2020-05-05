#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
vector<ll> A;
ll sum[100001];

ll check(ll p){
    ll c = 0;
    for(int i=0;i<N;i++){
        ll t = lower_bound(A.begin(),A.end(),p - A[i]) - A.begin();
        c += N - t;
    }
    return c;
}

ll ans(ll p){
    ll ret = 0;
    ll c = 0;
    for(int i=0;i<N;i++){
        ll t = lower_bound(A.begin(),A.end(),p - A[i]) - A.begin();
        c += N - t;
        ret += sum[t] + A[i] * (N-t);
    }
    ret += (M-c) * (p-1);
    return ret;
}

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    sum[N-1] = A[N-1];
    for(int i=N-2;i>=0;i--) sum[i] = sum[i+1] + A[i];
    ll sp = 0;
    ll ep = 300000;
    while(ep-sp>1){
        ll mp = (sp+ep)/2;
        ll p = check(mp);
        if(p <= M) ep = mp;
        else sp = mp;
    }
    cout << ans(ep) << endl;
    return 0;
}