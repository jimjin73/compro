#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

/* 
    RMQ：[0,n-1] について、区間ごとの最小値を管理する構造体
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最小の要素を取得。O(log(n))
*/

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


int main(){
    vector<ll> v = {1,3,5,4,6,2};
    segment_tree<ll> st(v);
    for(auto &e : st.tree) cout << e << endl;
    return 0;
}