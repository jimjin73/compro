#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
ll A[100001];
ll dp[1<<20];
vector<ll> ms[20];

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> A[i];
    for(int i=0;i<N;i++){
        ms[A[i]-1].push_back(i);
    }
    for(int i=0;i<(1<<M);i++) dp[i] = 1e12;
    dp[0] = 0;
    for(int i=0;i<M;i++){
        for(int j=0;j<(1<<M);j++){
            bitset<20> bt(j);
            if(bt.count() != i) continue;
            //cout << "bt=" << bt << endl;
            //cout << "cost=" << dp[j] << endl;
            for(int k=0;k<M;k++){
                if(bt[k] == 1) continue;
                ll s_len, e_len;
                s_len = e_len = 0;
                for(int l=0;l<M;l++){
                    if(bt[l] == 1) s_len += ms[l].size();
                } 
                e_len = s_len + ms[k].size();
                //cout << k << " " << s_len << " " << e_len << endl;
                auto s_itr = lower_bound(ms[k].begin(), ms[k].end(), s_len);
                auto e_itr = lower_bound(ms[k].begin(), ms[k].end(), e_len);
                //cout << e_itr - s_itr << "," << ms[k].size() - (e_itr - s_itr) << endl;
                dp[j|(1<<k)] = min(dp[j|(1<<k)], dp[j] + (ll)ms[k].size() - (e_itr - s_itr));
            }
        }
    }
    cout << dp[(1<<M)-1] << endl;
    return 0;
}