#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll a,b,c,d;
    ll N;
    a=b=c=d=0;
    cin >> N;
    string s;
    for(int i=0;i<N;i++){
        cin >> s;
        if(s == "AC") a++;
        if(s=="WA") b++;
        if(s=="TLE") c++;
        if(s=="RE") d++;
    }
    cout << "AC x " << a << endl;
    cout << "WA x " << b << endl;
    cout << "TLE x " << c << endl;
    cout << "RE x " << d << endl;
    return 0;
}