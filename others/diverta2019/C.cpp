#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    vector<P> ans;
    ll N;
    cin >> N;
    vector<ll> v(N);
    for(int i=0;i<N;i++) cin >> v[i];
    sort(v.begin(),v.end());
    for(int i=1;i<N-1;i++){
        if(v[i] > 0){
            ans.push_back({v[0],v[i]});
            v[0] -= v[i];
        }else{
            ans.push_back({v[N-1],v[i]});
            v[N-1] -= v[i];
        }
    }
    ans.push_back({v[N-1],v[0]});
    cout << v[N-1] - v[0] << endl;
    for(auto &e : ans){
        cout << e.first << " " << e.second << endl;
    }
    return 0;
}