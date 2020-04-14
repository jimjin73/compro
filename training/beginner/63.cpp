#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll m[310][310];
bool f[310][310];

int main(){
    cin >> N;
    ll sum = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> m[i][j];
            sum += m[i][j];
            f[i][j] = true;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(i == j || j == k || k == i) continue;
                if(m[j][k] > m[j][i] + m[i][k]){
                    cout << -1 << endl;
                    return 0;
                }
                if(m[j][k] == m[j][i] + m[i][k] && f[j][k]){
                    sum -= m[j][k];
                    f[j][k] = false;
                }
            }
        }
    }
    cout << sum / 2 << endl;
    return 0;
}