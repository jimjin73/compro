#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
vector<ll> v;
ll a[100000];

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    for(int i=0;i<N;i++){
        cout << lower_bound(v.begin(), v.end(), a[i]) - v.begin() << endl;
    }
    return 0;
}