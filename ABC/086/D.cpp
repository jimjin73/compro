#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,K;
ll w[1010][1010];
ll b[1010][1010];

void sets(ll x, ll y, char c){
    int f = 1;
    if(c == 'B') f *= -1;
    if((x / K)%2 == 1) f *= -1;
    x %= K;
    if((y / K)%2 == 1) f *= -1;
    y %= K;
    if(f > 0) w[x][y]++;
    else b[x][y]++;
}

ll W(ll a, ll bb, ll c, ll d){
    if(a > c || bb > d) return 0;
    ll ret = w[c][d];
    if(a > 0) ret -= w[a-1][d];
    if(bb > 0) ret -= w[c][bb-1];
    if(a>0 && bb>0) ret += w[a-1][bb-1];
    return ret;
}

ll B(ll a, ll bb, ll c, ll d){
    if(a > c || bb > d) return 0;
    ll ret = b[c][d];
    if(a > 0) ret -= b[a-1][d];
    if(bb > 0) ret -= b[c][bb-1];
    if(a>0 && bb>0) ret += b[a-1][bb-1];
    return ret;
}

ll get(ll x, ll y){
    ll a = W(0,0,x-1,y-1) + W(x,y,K-1,K-1) + B(0,y,x-1,K-1) + B(x,0,K-1,y-1);
    ll b = B(0,0,x-1,y-1) + B(x,y,K-1,K-1) + W(0,y,x-1,K-1) + W(x,0,K-1,y-1);
    return max(a,b);
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        ll x,y;
        char c;
        cin >> x >> y >> c;
        sets(x,y,c);
    }

    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            if(i>0){
                w[i][j] += w[i-1][j];
                b[i][j] += b[i-1][j];
            }
            if(j>0){
                w[i][j] += w[i][j-1];
                b[i][j] += b[i][j-1];
            }
            if(i>0 && j>0){
                w[i][j] -= w[i-1][j-1];
                b[i][j] -= b[i-1][j-1];
            }
        }
    }

    ll max_v = 0;
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            max_v = max(max_v, get(i,j));
        }
    }
    cout << max_v << endl;
    return 0;
}