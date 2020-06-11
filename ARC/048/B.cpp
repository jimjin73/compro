#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
ll R[100010];
ll H[100010][3];
P p[100010];

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        ll r,h;
        cin >> r >> h;
        p[i] = {r-1,h-1};
        R[r-1]++;
        H[r-1][h-1]++;
    }
    for(int i=0;i<=100000;i++) R[i+1] += R[i];
    for(int i=0;i<N;i++){
        ll a,b,c;
        a=b=c=0;
        if(p[i].first > 0) a += R[p[i].first-1];
        c += N - R[p[i].first];
        b += H[p[i].first][p[i].second] - 1;
        a += H[p[i].first][(p[i].second+1)%3];
        c += H[p[i].first][(p[i].second+2)%3];
        cout << a << " " << c << " " << b << endl;
    }
    return 0;
}