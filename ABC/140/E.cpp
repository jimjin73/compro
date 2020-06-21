#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
ll sum;
ll p[100000];
vector<P> v;
set<ll> S;

auto ptr(auto itr, ll p){
    if(p > 0){
        for(int i=0;i<p;i++) itr++;
    }
    if(p < 0){
        for(int i=0;i<(-p);i++) itr--;
    }
    return itr;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        ll tmp;
        cin >> tmp;
        v.push_back({tmp,i});
    }
    sort(v.rbegin(),v.rend());
    S.insert(v[0].second);
    S.insert(-1);
    S.insert(N);
    sum = 0;
    for(int i=1;i<N;i++){
        ll n = v[i].first;
        ll ind = v[i].second;
        auto ep = S.upper_bound(ind);
        ll s_ind,e_ind;
        s_ind = *(ptr(ep,-1));
        e_ind = *(ptr(ep,0));
        if(s_ind == -1){
            ll v_ind = *(ptr(ep,1));
            sum += (ind + 1) * (v_ind - e_ind) * n;
            //cout << s_ind << " [" << ind << "] " << e_ind << " " << v_ind << endl;
            S.insert(ind);
            continue;
        }
        if(e_ind == N){
            ll v_ind = *(ptr(ep,-2));
            sum += (N - ind) * (s_ind - v_ind) * n;
            //cout << v_ind << " " << s_ind << " [" << ind << "] " << e_ind << endl;
            S.insert(ind);
            continue;
        }
        ll vs_ind = *(ptr(ep,-2));
        ll ve_ind = *(ptr(ep,1));
        //cout << vs_ind << " " << s_ind << " [" << ind << "] " << e_ind << " " << ve_ind << endl;
        sum += (ind - s_ind) * (ve_ind - e_ind) * n;
        sum += (e_ind - ind) * (s_ind - vs_ind) * n;
        S.insert(ind);
    }
    cout << sum << endl;
    return 0;
}