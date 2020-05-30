#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,K,C;
string s;
vector<ll> l,r;

int main(){
    cin >> N >> K >> C;
    cin >> s;
    ll i = 0;
    while(l.size() < K && i < N){
        if(s[i] == 'x'){
            i++;
            continue;
        }
        l.push_back(i);
        i+=C+1;
    }
    i = N-1;
    while(r.size() < K && i >= 0){
        if(s[i] == 'x'){
            i--;
            continue;
        }
        r.push_back(i);
        i-=C+1;
    }
    sort(r.begin(),r.end());
    for(int i=0;i<K;i++){
        if(l[i]==r[i]) cout << l[i]+1 << endl;
    }
    return 0;
}