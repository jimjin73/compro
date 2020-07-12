#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll L,R,d;
    cin >> L >> R >> d;
    cout << R / d - (L-1) / d << endl;
    return 0;
}