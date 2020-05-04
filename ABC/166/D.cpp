#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll X;
vector<ll> v;

ll pow(ll n){
    return n*n*n*n*n;
}

int main(){
    cin >> X;
    v.push_back(0);
    for(int i=1;i<=200;i++){
        ll x = pow(i);
        v.push_back(x);
        v.push_back(-x);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<=401;i++){
        for(int j=0;j<=401;j++){
            if(i==j) continue;
            if(v[i] - v[j] == X){
                cout << i - 200 << " " << j - 200 << endl;
                return 0;
            }
        }
    }
    return 0;
}