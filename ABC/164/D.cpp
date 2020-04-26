#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
ll memo[2][2019];

int main(){
    cin >> s;
    ll sum = 0;
    for(int i=0;i<2019;i++) memo[0][i] = 0;
    memo[0][s[0]-'0']++;
    for(int i=1;i<s.size();i++){
        for(int j=0;j<2019;j++) memo[1][j] = 0;
        memo[1][s[i]-'0']++;
        for(int j=0;j<2019;j++) memo[1][((j*10)+ (s[i]-'0'))%2019] += memo[0][j];
        sum += memo[1][0];
        for(int j=0;j<2019;j++) memo[0][j] = memo[1][j];
    }
    cout << sum << endl;
    return 0;
}