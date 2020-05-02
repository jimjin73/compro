#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> X,Y,Z;
ll a[120],b[120],c[120],d[120],e[120],f[120];
ll N,K;
ll C[120][120][120];

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i] >> f[i];
        X.push_back(a[i]);
        X.push_back(d[i]);
        Y.push_back(b[i]);
        Y.push_back(e[i]);
        Z.push_back(c[i]);
        Z.push_back(f[i]);
    }

    X.push_back(-1);
    Y.push_back(-1);
    Z.push_back(-1);
    X.push_back(1000001);
    Y.push_back(1000001);
    Z.push_back(1000001);
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    sort(Z.begin(),Z.end());
    X.erase(unique(X.begin(),X.end()), X.end());
    Y.erase(unique(Y.begin(),Y.end()), Y.end());
    Z.erase(unique(Z.begin(),Z.end()), Z.end());

    for(int i=0;i<X.size();i++){
        for(int j=0;j<Y.size();j++){
            for(int k=0;k<Z.size();k++){
                C[i][j][k] = 0;
            }
        }
    }

    for(int i=0;i<N;i++){
        ll min_x = lower_bound(X.begin(),X.end(),a[i]) - X.begin();
        ll max_x = lower_bound(X.begin(),X.end(),d[i]) - X.begin();
        ll min_y = lower_bound(Y.begin(),Y.end(),b[i]) - Y.begin();
        ll max_y = lower_bound(Y.begin(),Y.end(),e[i]) - Y.begin();
        ll min_z = lower_bound(Z.begin(),Z.end(),c[i]) - Z.begin();
        ll max_z = lower_bound(Z.begin(),Z.end(),f[i]) - Z.begin();
        C[min_x][min_y][min_z]++;
        C[max_x][min_y][min_z]--;
        C[min_x][max_y][min_z]--;
        C[min_x][min_y][max_z]--;
        C[max_x][max_y][min_z]++;
        C[min_x][max_y][max_z]++;
        C[max_x][min_y][max_z]++;
        C[max_x][max_y][max_z]--;
    }

    for(int i=1;i<X.size();i++){
        for(int j=1;j<Y.size();j++){
            for(int k=1;k<Z.size();k++){
                C[i][j][k] += C[i-1][j][k] + C[i][j-1][k] + C[i][j][k-1] - C[i-1][j-1][k] - C[i-1][j][k-1] - C[i][j-1][k-1] + C[i-1][j-1][k-1];
            }
        }
    }
    ll V = 0;
    for(int i=0;i<X.size()-1;i++){
        for(int j=0;j<Y.size()-1;j++){
            for(int k=0;k<Z.size()-1;k++){
                if(C[i][j][k] >= K){
                    V += (X[i+1]-X[i]) * (Y[j+1]-Y[j]) * (Z[k+1]-Z[k]);
                }
            }
        }
    }
    cout << V << endl;
    return 0;
}