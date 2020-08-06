#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

bool check(vector<ll> &v, ll p, ll K){
    ll c = 0;
    for(auto &e : v){
        c += e / p;
        if(e % p == 0) c--;
    }
    return c <= K;
}

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    ll sp = 0;
    ll ep = 1e9+1;
    while(sp+1<ep){
        ll p = (sp+ep)/2;
        if(check(A,p,K)){
            ep = p;
        }else{
            sp = p;
        }
    }
    cout << ep << endl;
    return 0;
}