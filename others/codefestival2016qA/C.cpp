#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

string s;
ll K;

int main(){
    cin >> s;
    cin >> K;
    for(int i=0;i<s.size();i++){
        ll c = s[i] - 'a';
        if(c == 0) continue;
        if(K < 26-c) continue;
        s[i] = 'a';
        K -= (26-c);
    }
    K %= 26;
    s[s.size()-1] += K;
    cout << s << endl;
    return 0;
}