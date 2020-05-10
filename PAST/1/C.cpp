#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> v;

int main(){
    for(int i=0;i<6;i++){
        ll a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    cout << v[3] << endl;
    return 0;
}