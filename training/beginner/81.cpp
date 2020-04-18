#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll c[1000010];

int main(){
    cin >> N;
    for(int i=0;i<=1000000;i++) c[i] = 0;
    for(int i=0;i<N;i++){
        ll a,b;
        cin >> a >> b;
        c[a]++;
        c[b+1]--;
    }
    for(int i=1;i<=1000000;i++) c[i] += c[i-1];
    ll max_v = 0;
    for(int i=0;i<=1000000;i++) max_v = max(max_v, c[i]);
    cout << max_v << endl;
    return 0;
}