#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,K;
ll A[500];
vector<ll> v;

bool check(ll e){
    vector<ll> M;
    M.push_back(0);
    for(int i=0;i<N;i++) M.push_back(A[i]%e);
    sort(M.begin(),M.end());
    for(int i=1;i<=N;i++) M[i] += M[i-1];
    ll D = 1e18;
    for(int i=0;i<=N;i++){
        D = min(D, max(M[i],(N-i)*e-(M[N]-M[i])));
    }
    return D <= K;
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> A[i];
    ll sum = 0;
    for(int i=0;i<N;i++) sum += A[i];
    v.push_back(1);
    for(int i=1;i*i<=sum;i++){
        if(sum % i == 0){
            v.push_back(i);
            if(i * i != sum) v.push_back(sum / i);
        }
    }
    sort(v.rbegin(),v.rend());
    for(auto &e : v){
        if(check(e)){
            cout << e << endl;
            break;
        }
    }
    return 0;
}