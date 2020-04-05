#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> v;

bool check(ll a, ll b){
    while(b > a){
        if(b % a != 0) return false;
        b /= a;
    }
    return true;
}

int main(){
    ll N;
    cin >> N;
    for(ll i=2;i*i <= N;i++){
        if(N % i == 0){
            v.push_back(i);
            v.push_back(N / i);
        }
    }
    ll c = 0; 
    for(int i=0;i<v.size();i++){
        ll q = v[i] - 1;
        vector<ll> w;
        for(int j=2;j*j <=q;j++){
            if(q % j == 0){
                w.push_back(j);
                w.push_back(q/j);
            }
        }
        ll t = N / q;
        bool f = false;
        for(int j=0;j<w.size();j++){
            if(check(w[j], t)){
                f = true;
            }
        }
        if(f) c++;
    }
    cout << c << endl;
    return 0;
}