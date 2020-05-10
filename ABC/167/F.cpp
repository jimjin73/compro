#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
string s[2000050];
vector<pair<ll,ll>> pv,mv;

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> s[i];
    for(int i=0;i<N;i++){
        ll l,r;
        l = r = 0;
        for(int j=0;j<s[i].size();j++){
            if(s[i][j] == '('){
                l++;
            }else{
                if(l > 0) l--;
                else r++;
            }
        }
        if(l > 0) pv.push_back(make_pair(r,l));
        else mv.push_back(make_pair(r,l));
    }
    sort(pv.begin(),pv.end());
    ll L = 0;
    for(auto &e : pv){
        ll r = e.first;
        ll l = e.second;
        if(r > L){
            cout << "No" << endl;
            return 0;
        }
        L += (l-r);
    }
    for(auto &e : mv){
        ll r = e.first;
        ll l = e.second;
        if(r > L){
            cout << "No" << endl;
            return 0;
        }
        L -= r;
    }
    if(L != 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}