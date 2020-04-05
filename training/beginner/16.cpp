#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> a;
ll x[10];
ll y[10];

double dist(ll a,ll b,ll c,ll d){
    ll t = (a-c) * (a-c) + (b-d) * (b-d);
    return sqrt(t);
}

int main(){
    int N;
    cin >> N;
    double sum = 0;
    ll p = 0;
    for(int i=0;i<N;i++) cin >> x[i] >> y[i];
    for(int i=0;i<N;i++) a.push_back(i);
    do{
        p++;
        for(int i=1;i<N;i++){
            sum += dist(x[a[i]],y[a[i]],x[a[i-1]],y[a[i-1]]);
        }
    }while(next_permutation(a.begin(), a.end()));
    cout << fixed << setprecision(15) << sum / p << endl;
    return 0;
}