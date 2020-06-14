#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

bool f[1000001];
ll N;
ll A[200001];
vector<ll> v;
ll t[1000001];

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
        v.push_back(A[i]);
        t[A[i]]++;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++){
        if(f[v[i]]) continue;
        if(i > 0){
            if(v[i] == v[i-1]) continue;
        }
        for(int j=2;j*v[i]<=1000000;j++) f[j*v[i]] = true;
    }
    ll c = 0;
    for(int i=0;i<N;i++){
        if(f[A[i]]) continue;
        if(t[A[i]]>1) continue;
        c++;
    }
    cout << c << endl;
    return 0;
}