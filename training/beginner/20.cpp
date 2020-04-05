#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
vector<ll> A;
vector<ll> B;
vector<ll> C;

int main(){
    ll t;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> t;
        A.push_back(t);
    }
    for(int i=0;i<N;i++){
        cin >> t;
        B.push_back(t);
    }
    for(int i=0;i<N;i++){
        cin >> t;
        C.push_back(t);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    sort(C.begin(),C.end());
    ll n = 0;
    for(int i=0;i<N;i++){
        auto itra = lower_bound(A.begin(),A.end(),B[i]);
        auto itrc = upper_bound(C.begin(),C.end(),B[i]);
        ll ap = (ll)(itra - A.begin());
        ll cp = N - (ll)((itrc - C.begin()));
        n += ap * cp;
    }
    cout << n << endl;
    return 0;
}