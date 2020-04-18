#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll M,N;
ll K;
ll a[100000], b[100000], c[100000], d[100000];
ll jmap[1010][1010], omap[1010][1010], imap[1010][1010];
string s[1010];

int main(){
    cin >> M >> N;
    cin >> K;
    for(int i=0;i<M;i++) cin >> s[i];
    for(int i=0;i<K;i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    for(int i=0;i<=M;i++) jmap[i][0] = omap[i][0] = imap[i][0] = 0;
    for(int i=0;i<=N;i++) jmap[0][i] = omap[0][i] = imap[0][i] = 0;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            jmap[i][j] = omap[i][j] = imap[i][j] = 0;
            if(s[i-1][j-1] == 'J') jmap[i][j]++;
            else if(s[i-1][j-1] == 'O') omap[i][j]++;
            else imap[i][j]++;
            jmap[i][j] += jmap[i-1][j] + jmap[i][j-1] - jmap[i-1][j-1];
            omap[i][j] += omap[i-1][j] + omap[i][j-1] - omap[i-1][j-1];
            imap[i][j] += imap[i-1][j] + imap[i][j-1] - imap[i-1][j-1];
        }
    }
    for(int i=0;i<K;i++){
        ll jj,ii,oo;
        jj = jmap[c[i]][d[i]] - jmap[c[i]][b[i]-1] - jmap[a[i]-1][d[i]] + jmap[a[i]-1][b[i]-1];
        oo = omap[c[i]][d[i]] - omap[c[i]][b[i]-1] - omap[a[i]-1][d[i]] + omap[a[i]-1][b[i]-1];
        ii = imap[c[i]][d[i]] - imap[c[i]][b[i]-1] - imap[a[i]-1][d[i]] + imap[a[i]-1][b[i]-1];
        cout << jj << " " << oo << " " << ii << endl;
    }
    return 0;
}