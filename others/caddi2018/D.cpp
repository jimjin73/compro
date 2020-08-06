#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll N;
    cin >> N;
    vector<ll> v(N);
    for(int i=0;i<N;i++) cin >> v[i];
    bool f = true;
    for(int i=0;i<N;i++) if(v[i]%2==1) f = false;
    if(!f) cout << "first" << endl;
    else cout << "second" << endl;
    return 0;
}