#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> v[100001];
ll a[100000];
ll b[100000];
unordered_map<ll,ll> um;
bool f[100000];
ll N;

int main(){
    cin >> N;
    for(int i=0;i<N-1;i++){
        cin >> a[i] >> b[i];
        a[i]--,b[i]--;
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    ll K = 0;
    for(int i=0;i<N;i++){
        K = max(K, (ll)v[i].size());
        sort(v[i].begin(),v[i].end());
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++) f[j] = true;
        ll p = 0;
        for(int j=0;j<v[i].size();j++){
            ll x = i;
            ll y = v[i][j];
            if(x > y){
                f[um[y*100000+x]] = false;
                continue;
            }
            while(!f[p]) p++;
            um[x*100000+y] = um[y*100000+x] = p;
            f[p] = false;
        }
    }
    cout << K << endl;
    for(int i=0;i<N-1;i++){
        cout << um[a[i]*100000+b[i]] + 1 << endl;
    }
    return 0;
}