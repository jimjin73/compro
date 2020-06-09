#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<pair<ll,ll>,ll> P;

ll L;
vector<P> v;

int main(){
    cin >> L;
    bitset<19> bt(L);
    ll l = 0;
    while(L > 1){
        l++;
        L /= 2;
    }
    ll c = 0;
    for(int i=1;i<=l;i++){
        v.push_back({{i,i+1},0});
        v.push_back({{i,i+1},1<<(i-1)});
        if(bt[i-1]==1){
            v.push_back({{i,20},(1<<l)+c});
            c += 1 << (i-1);
        }
    }
    for(int i=l+1;i<20;i++){
        v.push_back({{i,i+1},0});
    }
    cout << 20 << " " << v.size() << endl;
    for(auto &e : v){
        cout << e.first.first << " " << e.first.second << " " << e.second << endl;
    }
    return 0;
}