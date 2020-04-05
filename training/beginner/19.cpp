#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll D; // 全長
ll n; // 店舗数
ll m; // 注文数
vector<ll> d;
vector<ll> k;

int main(){
    ll t;
    cin >> D;
    cin >> n;
    cin >> m;
    d.push_back(0);
    for(int i=0;i<n-1;i++){
        cin >> t;
        d.push_back(t);
    }
    d.push_back(D);
    sort(d.begin(),d.end());
    for(int i=0;i<m;i++){
        cin >> t;
        k.push_back(t);
    }
    ll sum = 0;
    for(int i=0;i<m;i++){
        auto itr = lower_bound(d.begin(),d.end(), k[i]);
        sum += min(abs(*itr-k[i]), abs(*(itr-1)-k[i]));
    }
    cout << sum << endl;
    return 0;
}