#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll H,W,N;
map<P,ll> um;

int main(){
    cin >> H >> W >> N;
    for(int i=0;i<N;i++){
        ll a,b;
        cin >> a >> b;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                ll aa = a - j;
                ll bb = b - k;
                if(aa >= 1 && bb >= 1 && aa <= H-2 && bb <= W-2){
                    um[make_pair(aa,bb)]++;
                }
            }
        }
    }
    vector<ll> ans(9,0);
    ll total = 0;
    for(auto &e : um){
        ans[e.second-1]++;
        total++;
    }
    cout << (H-2) * (W-2) - total << endl;
    for(auto &e : ans) cout << e << endl;
    return 0;
}