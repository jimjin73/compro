#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,W;
ll v[200], w[200];
ll dp[200][200001];
ll INF = 1e15;


// N小さい
void func1(){
    vector<pair<ll,ll>> a;
    ll n = min((ll)15, N);
    for(int i=1;i<(1<<n);i++){
        bitset<15> bt(i);
        ll v_sum, w_sum;
        v_sum = w_sum = 0;
        for(int j=0;j<n;j++){
            if(bt[j]==0) continue;
            v_sum += v[j];
            w_sum += w[j];
        }
        a.push_back(make_pair(w_sum,v_sum));
    }
    sort(a.begin(),a.end());
    vector<ll> ww,vv;
    for(auto &e : a){
        ll tmp_w = e.first;
        ll tmp_v = e.second;
        if(ww.size()==0){
            ww.push_back(tmp_w);
            vv.push_back(tmp_v);
            continue;
        }
        if(vv[vv.size()-1] >= tmp_v) continue;
        ww.push_back(tmp_w);
        vv.push_back(tmp_v);
    }
    if(N < 15){
        ll ind = upper_bound(ww.begin(),ww.end(),W) - ww.begin();
        if(ind > 0) cout << vv[ind-1] << endl;
        else cout << 0 << endl;
    }else{
        ll max_v = 0;
        ll n = N - 15;
        for(int i=0;i<(1<<n);i++){
            bitset<15> bt(i);
            ll v_sum, w_sum;
            v_sum = w_sum = 0;
            for(int j=0;j<n;j++){
                if(bt[j]==0) continue;
                v_sum += v[j+15];
                w_sum += w[j+15];
            }
            if(w_sum > W) continue;
            ll ind = upper_bound(ww.begin(),ww.end(),W-w_sum) - ww.begin();
            ll tmp_v;
            if(ind > 0) tmp_v = vv[ind-1];
            else tmp_v = 0;
            max_v = max(max_v, v_sum + tmp_v);
        }
        cout << max_v << endl;
    }
}

// v小さい
void func2(){
    dp[0][0] = 0;
    for(int i=1;i<=200000;i++){
        if(i <= v[0]) dp[0][i] = w[0];
        else dp[0][i] = INF;
    }
    for(int i=1;i<N;i++){
        for(int j=200000;j>=0;j--){
            dp[i][j] = dp[i-1][j];
            if(j < 200000) dp[i][j] = min(dp[i][j], dp[i][j+1]);
            if(j - v[i] >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j - v[i]] + w[i]);
        }
    }
    ll max_v = 0;
    for(int i=0;i<=200000;i++){
        if(dp[N-1][i] <= W) max_v = i;
    }
    cout << max_v << endl;
}

// w小さい
void func3(){
    dp[0][0] = 0;
    for(int i=1;i<=200000;i++){
        if(i < w[0]) dp[0][i] = 0;
        else dp[0][i] = v[0];
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<=200000;j++){
            dp[i][j] = dp[i-1][j];
            if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1]);
            if(j - w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
        }
    }
    cout << dp[N-1][W] << endl;
}

int main(){
    cin >> N >> W;
    for(int i=0;i<N;i++)  cin >> v[i] >> w[i];
    if(N <= 30) func1();
    else{
        bool f = true;
        for(int i=0;i<N;i++){
            if(v[i] > 1000) f = false;
        }
        if(f){
            func2();
        }else{
            func3();
        }
    }
    return 0;
}