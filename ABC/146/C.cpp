#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A,B,X;

bool check(ll p){
    string s = to_string(p);
    ll C = A * p + B * (ll)s.size();
    return C <= X;
}

int main(){
    cin >> A >> B >> X;
    ll sp = 0;
    ll ep = 1e9+1;
    while(ep-sp>1){
        ll p = (ep+sp)/2;
        if(check(p)) sp = p;
        else ep = p;
    }
    cout << sp << endl;
    return 0;
}