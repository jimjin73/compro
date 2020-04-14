#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
ll m[310][310];
ll max_l[310];

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) m[i][j] = 0;
            else m[i][j] = 1e12;
        }
        max_l[i] = 0;
    }
    ll a,b,t;
    for(int i=0;i<M;i++){
        cin >> a >> b >> t;
        m[a-1][b-1] = m[b-1][a-1] = t;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                m[j][k] = min(m[j][k], m[j][i] + m[i][k]);
            }
        }
    }
    ll min_l = 1e12;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            max_l[i] = max(max_l[i], m[i][j]);
        }
        min_l = min(max_l[i], min_l);
    }
    cout << min_l << endl;
    return 0;
}