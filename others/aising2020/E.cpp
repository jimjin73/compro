#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll T;
    vector<ll> ans;
    cin >> T;
    for(int t=0;t<T;t++){
        ll N;
        cin >> N;
        ll tmp_ans = 0;
        vector<vector<ll>> v_right(N);
        vector<vector<ll>> v_left(N);
        for(int n=0;n<N;n++){
            ll k,l,r;
            cin >> k >> l >> r;
            if(l>r) v_left[k-1].push_back(l-r);
            else v_right[k-1].push_back(r-l);
            tmp_ans += min(l,r);
        }
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int i=0;i<N;i++){
            for(auto &e : v_left[i]){
                pq.push(e);
            }
            while(pq.size() > i+1) pq.pop();
        }
        while(!pq.empty()){
            tmp_ans += pq.top();
            pq.pop();
        }
        for(int i=N-2;i>=0;i--){
            for(auto &e : v_right[i]){
                pq.push(e);
            }
            while(pq.size() > N - i - 1) pq.pop();
        }
        while(!pq.empty()){
            tmp_ans += pq.top();
            pq.pop();
        }
        ans.push_back(tmp_ans);
    }
    for(auto &e : ans) cout << e << endl;
    return 0;
}