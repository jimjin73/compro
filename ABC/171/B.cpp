#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,K;
vector<ll> v;

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    ll sum = 0;
    for(int i=0;i<K;i++) sum += v[i];
    cout << sum << endl;
    return 0;
}