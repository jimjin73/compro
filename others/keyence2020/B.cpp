#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

template <typename T>
struct segment_tree{
    const T INF = numeric_limits<T>::max();
    int num_of_leafs;
    vector<T> tree;
    int P2(int t){
        int s = 1;
        while(t > s) s <<= 1;
        return s;
    }
    segment_tree(vector<T> &v) : num_of_leafs(P2(v.size())), tree(num_of_leafs*2-1, INF){        
        for(int i=0;i<v.size();i++) tree[i + num_of_leafs - 1] = v[i];
        update_all();
    }
    void update_all(){ //複数変更をまとめて反映させたい場合に使う
        for(int p=num_of_leafs-2;p>=0;p--) tree[p] = min(tree[p*2+1], tree[p*2+2]);
    }
    void update(int i, T x) {
        i += num_of_leafs - 1;
        tree[i] = x;
        while(i > 0){
            i = (i-1)/2;
            tree[i] = min(tree[i*2+1], tree[i*2+2]);
        }
    }
    T query(int a, int b){return query_sub(a, b, 0, 0, num_of_leafs);}
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return INF;
        } else if (a <= l && r <= b) {
            return tree[k];
        } else {
            T vl = query_sub(a, b, k*2+1, l, (l+r)/2);
            T vr = query_sub(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
};

ll N;
vector<P> v;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        ll a,b;
        cin >> a >> b;
        v.push_back({a-b,a+b});
    }
    sort(v.begin(),v.end());
    vector<ll> w;
    for(auto &e : v){
        w.push_back(e.second);
    }
    segment_tree<ll> st(w);
    ll ans = 0;
    ll x = -1e18;
    while(true){
        ll idx = lower_bound(v.begin(),v.end(),make_pair(x,(ll)-1e18)) - v.begin();
        if(idx >= N) break;
        ans++;
        x = st.query(idx,N);
    }
    cout << ans << endl;
    return 0;
}