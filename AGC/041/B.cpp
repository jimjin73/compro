#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> A;
ll N,M,V,P;

bool check(int p){
    if(N-p <= P) return true;
    vector<ll> v;
    for(int i=0;i<N;i++){
        if(v.size() >= N-P) break;
        if(i==p) continue;
        v.push_back(A[i]);
    }
    ll ap = A[p] + M;
    if(ap < v.back()) return false;
    ll ac = 0;
    for(auto &e : v) ac += min(M,ap-e);
    if(ac >= (V-P) * M) return true;
    else return false;
}

int main(){
    cin >> N >> M >> V >> P;
    for(int i=0;i<N;i++){
        ll a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    int sp = -1;
    int ep = N-1;
    while(ep-sp > 1){
        int p = (ep+sp) / 2;
        if(check(p)){
            ep = p;
        }else{
            sp = p;
        }
    }
    cout << N-ep << endl;
    return 0;
}