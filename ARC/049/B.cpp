#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll x[1000],y[1000],c[1000];
ll N;

bool check(ld l){
    vector<ld> ux,dx,uy,dy;
    for(int i=0;i<N;i++){
        ux.push_back((ld)x[i] + l / (ld)c[i]);
        dx.push_back((ld)x[i] - l / (ld)c[i]);
        uy.push_back((ld)y[i] + l / (ld)c[i]);
        dy.push_back((ld)y[i] - l / (ld)c[i]);  
    }
    ld min_ux,max_dx,min_uy,max_dy;
    min_ux = min_uy = 1e11;
    max_dx = max_dy = -1e11;
    for(int i=0;i<N;i++){
        max_dx = max(max_dx, dx[i]);
        max_dy = max(max_dy, dy[i]);
        min_ux = min(min_ux, ux[i]);
        min_uy = min(min_uy, uy[i]);
    }
    if(max_dx <= min_ux && max_dy <= min_uy) return true;
    return false;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x[i] >> y[i] >> c[i];
    }
    ld sp = 0.0;
    ld ep = 1e10;
    while(ep-sp > 1e-5){
        ld p = (sp+ep)/2.0;
        if(check(p)){
            ep = p;
        }else{
            sp = p;
        }
    }
    cout << fixed << setprecision(15) << ep << endl;
    return 0;
}