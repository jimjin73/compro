#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll H,W,K;
string s[10];
string t[10];

int main(){
    ll ans = 0;
    cin >> H >> W >> K;
    for(int i=0;i<H;i++) cin >> s[i];
    for(int i=0;i<(1<<(H+W));i++){
        bitset<12> b(i);
        for(int h=0;h<H;h++) t[h] = s[h];
        for(int h=0;h<H;h++){
            if(b[h] == 0) continue;
            for(int w=0;w<W;w++) t[h][w] = 'x';
        }
        for(int w=0;w<W;w++){
            if(b[H+w] == 0) continue;
            for(int h=0;h<H;h++) t[h][w] = 'x';
        }
        ll c = 0;
        for(int h=0;h<H;h++){
            for(int w=0;w<W;w++){
                if(t[h][w] == '#') c++;
            }
        }
        if(c==K) ans++;
    }
    cout << ans << endl;
    return 0;
}