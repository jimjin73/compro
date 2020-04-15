#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int p[100001];
ll Q;
ll l[100001];
ll r[100001];
int ans[100001];

int main(){
    ll Q;
    cin >> Q;
    ll N = 100000;
    for(int i=0;i<Q;i++) cin >> l[i] >> r[i];
    for(int i=1;i<=N;i++) p[i] = 1;
    for(int i=2;i*i<=N;i++){
        if(p[i] != 1) continue;
        for(int j=2;i*j<=N;j++) p[i*j]++;
    }
    p[1] = 0;
    for(int i=0;i<=N;i++){
        if(i%2 == 0){
            ans[i] = 0;
            continue;
        }
        if(p[i] == 1 && p[(i+1)/2] == 1) ans[i] = 1;
        else ans[i] = 0;
    }
    for(int i=2;i<=N;i++) ans[i] += ans[i-1];
    for(int i=0;i<Q;i++){
        cout << ans[r[i]] - ans[l[i]-1] << endl;
    }
    return 0;
}