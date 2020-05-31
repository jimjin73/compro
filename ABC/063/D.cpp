#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll h[100000];
ll N,A,B;

bool isOK(ll p){
    ll c = 0;
    for(int i=0;i<N;i++){
        ll t = h[i] - p*B;
        if(t <= 0) continue;
        c += t / (A-B);
        if(t % (A-B) != 0) c++;
    }
    return c <= p;
}

int main(){
    cin >> N >> A >> B;
    for(int i=0;i<N;i++) cin >> h[i];
    ll sp,ep;
    sp = 0;
    ep = 2e9;
    while(ep-sp>1){
        ll p = (sp+ep)/2;
        if(isOK(p)) ep = p;
        else sp = p;
    }
    cout << ep << endl;
    return 0;
}