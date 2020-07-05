#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
ll D[13];

bool dfs(vector<ll> &v,ll d,ll s){
    if(d == 13) return true;
    if(D[d] == 0) return dfs(v, d+1, s);
    if(D[d] == 2){
        if(d*2 < s || 24-d*2 < s) return false;
        for(auto &e : v){
            if(abs(e-d)<s || 24 - abs(e-d)<s) return false;
            if(abs(e-(24-d))<s || 24 - abs(e-(24-d))<s) return false;
        }
        v.push_back(d);
        v.push_back(24-d);
        bool f = dfs(v,d+1,s);
        v.pop_back();
        v.pop_back();
        return f;
    }
    bool b;
    b = true;
    for(auto &e : v){
        if(abs(e-d)<s || 24 - abs(e-d)<s) b = false;
    }
    if(b){
        v.push_back(d);
        bool f = dfs(v,d+1,s);
        v.pop_back();
        if(f) return true;
    }
    b = true;
    for(auto &e : v){
        if(abs(e-(24-d))<s || 24 - abs(e-(24-d))<s) return false;
    }
    if(b && d != 12){
        v.push_back(24-d);
        bool f = dfs(v,d+1,s);
        v.pop_back();
        if(f) return true;
    }
    return false;
}

bool check(ll s){
    vector<ll> v;
    v.push_back(0);
    return dfs(v,1,s);
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        ll d;
        cin >> d;
        D[d]++;
    }
    if(D[0]>0){
        cout << 0 << endl;
        return 0;
    }
    for(int i=1;i<=11;i++){
        if(D[i] > 2){
            cout << 0 << endl;
            return 0;
        }
    }
    if(D[12] > 1){
        cout << 0 << endl;
        return 0;
    }
    ll max_s = 24 / (N+1);
    for(int s = max_s;s > 0;s--){
        if(check(s)){
            cout << s << endl;
            break;
        }
    }
    return 0;
}