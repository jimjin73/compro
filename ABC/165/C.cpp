#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N,M,Q;
int a[50],b[50],c[50],d[50];
vector<int> v;
int max_v;

void dfs(int dd){
    if(dd == 0){
        for(int i=1;i<=M;i++){
            v.push_back(i);
            dfs(1);
            v.pop_back();
        }
        return;
    }
    if(dd == N){
        int vv = 0;
        for(int i=0;i<Q;i++){
            if(v[b[i]-1] - v[a[i]-1] == c[i]) vv += d[i];
        }
        max_v = max(max_v,vv);
        return;
    }
    for(int i=v[v.size()-1];i<=M;i++){
        v.push_back(i);
        dfs(dd+1);
        v.pop_back();
    }
}

int main(){
    cin >> N >> M >> Q;
    for(int i=0;i<Q;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    dfs(0);
    cout << max_v << endl;
    return 0;
}