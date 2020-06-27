#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

string s,t;

int main(){
    cin >> s;
    cin >> t;
    ll l = s.size();
    ll c = 0;
    for(int i=0;i<l;i++){
        if(s[i]!=t[i]) c++;
    }
    cout << c << endl;
    return 0;
}