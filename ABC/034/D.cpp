#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,K;
ll W[1000];
ll P[1000];

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> W[i] >> P[i];
    }
    long double ok,ng;
    ng = 100.0;
    ok = 0.0;
    while(ng-ok > 1e-10){
        long double target = (ng+ok) / 2.0;
        vector<long double> v;
        for(int i=0;i<N;i++){
            long double nacl = (long double)P[i] * W[i] / 100.0;
            long double h2o = (long double)W[i] - nacl;
            long double x = (target / 100.0 * h2o) / (1.0 - target / 100.0);
            v.push_back(nacl-x);
        }
        long double sum = 0.0;
        sort(v.rbegin(),v.rend());
        for(int i=0;i<K;i++){
            sum += v[i];
        }
        if(sum >= 0) ok = target;
        else ng = target;
    }
    cout << fixed << setprecision(15) << ok << endl;
    return 0;
}