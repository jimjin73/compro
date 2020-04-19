#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
ll x[200],y[200],r[200];

bool check(long double rr){
    for(int i=0;i<M;i++){
        for(int j=0;j<N+M;j++){
            if(i+N == j) continue;
            long double a = pow(x[i+N]-x[j],2) + pow(y[i+N]-y[j],2);
            long double b;
            if(j >= N){
                b = pow(2*rr,2);
            }else{
                b = pow(rr + (double)r[j],2);
            }
            if(a < b) return false;
        }
    }
    return true;
}

int main(){
    cin >> N >> M;
    ll min_r = 100;
    for(int i=0;i<N;i++) cin >> x[i] >> y[i] >> r[i];
    for(int i=0;i<N;i++) min_r = min(min_r,r[i]);
    for(int i=0;i<M;i++) cin >> x[i+N] >> y[i+N];
    long double sp,ep;
    sp = 0.0;
    ep = 100.0;
    while(ep - sp > 1e-7){
        long double p = (sp+ep) / 2;
        if(check(p)){
            sp = p;
        }else{
            ep = p;
        }
    }
    if((double)min_r > sp) cout << fixed << setprecision(15) << sp << endl;
    else cout << min_r << endl;
    return 0;
}