#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
ll l[100000];
ll a[100000];
ll mod = 1e5;

int main(){
    cin >> N >> M;
    l[0] = 0;
    for(int i=1;i<=N-1;i++) cin >> l[i];
    for(int i=0;i<M;i++) cin >> a[i];
    for(int i=1;i<=N-1;i++){
        l[i] += l[i-1];
        l[i] %= mod;
    }
    ll p = 0;
    ll sum = 0;
    //for(int i=0;i<=N-1;i++) cout << l[i] << ' ';
    //cout << endl;
    for(int i=0;i<M;i++){
        if(a[i] > 0) sum += l[p+a[i]] - l[p];
        else sum += l[p] - l[p+a[i]];
        p += a[i];
        sum %= mod;
        //cout << p << ',' << sum << endl;
    }
    cout << sum << endl;
    return 0;
}