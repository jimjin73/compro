#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll A[2010];
vector<pair<ll,ll>> v; //値,元の位置

bool check(ll n,ll sp, ll ep){
    ll cs,es;
    cs = es = 0;
    for(int i=n-1;i>=sp;i--){
        if(i+1 <= v[n].second) cs += v[n].first;
        else cs -= v[n].first;
        if(i >= v[i].second) cs += v[i].first;
        else cs -= v[i].first;
    }
    for(int i=n+1;i<=ep;i++){
        if(i-1 >= v[n].second) es += v[n].first;
        else es -= v[n].first;
        if(i <= v[i].second) es += v[i].first;
        else es -= v[i].first;
    }
    return cs > es;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++) v.push_back(make_pair(A[i],i));
    int sp = 0;
    int ep = N-1;
    for(int i=0;i<N;i++){
        ll max_v = 0;
        ll max_i = -1;
        for(int j=sp;j<=ep;j++){
            if(max_v < v[j].first){
                max_v = v[j].first;
                max_i = j;
            }
        }
        if(check(max_i,sp,ep)){
            for(int k=max_i;k>sp;k--) swap(v[k],v[k-1]);
            sp++;
        }else{
            for(int k=max_i;k<ep;k++) swap(v[k],v[k+1]);
            ep--;
        }
    }
    ll sum = 0;
    for(ll i=0;i<N;i++){
        sum += v[i].first * abs(i-v[i].second);
    }
    cout << sum << endl;
    return 0;
}