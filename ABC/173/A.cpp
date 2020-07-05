#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll N;
    cin >> N;
    ll t = 1000 - N % 1000;
    if(t==1000) t = 0;
    cout << t << endl;
    return 0;
}