#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int b[2][3];
int c[3][2];
int m[3][3];

int calcP(){
    int T = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            if(m[i][j] == m[i+1][j]) T += b[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            if(m[i][j] == m[i][j+1]) T += c[i][j];
        }
    }
    return T;
}

int dfs(int d){
    if(d == 9) return calcP();
    vector<int> v;
    int n = 1;
    if(d % 2 == 1) n++;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(m[i][j] != 0) continue;
            m[i][j] = n;
            v.push_back(dfs(d+1));
            m[i][j] = 0;
        }
    }
    sort(v.begin(),v.end());
    if(d % 2 == 0) return v.back();
    else return v.front();
}

int main(){
    int total = 0;
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cin >> b[i][j];
            total += b[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            cin >> c[i][j];
            total += c[i][j];
        }
    }
    int p = dfs(0);
    cout << p << endl;
    cout << total - p << endl;
    return 0;
}