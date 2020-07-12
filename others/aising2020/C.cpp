#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll C[20000];

int main(){
    ll N;
    cin >> N;
    for(int x=1;x<=100;x++){
        for(int y=1;y<=100;y++){
            for(int z=1;z<=100;z++){
                ll t = x*x+y*y+z*z+x*y+y*z+z*x;
                if(t<=15000) C[t]++;
            }
        }
    }
    for(int i=1;i<=N;i++) cout << C[i] << endl;
    return 0;
}