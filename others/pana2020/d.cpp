#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int N;
string c = "abcdefghijklm";

int dfs(int d, string s, int n){
    if(d == N){
        cout << s << endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        dfs(d+1, s+c[i], n);
    }
    dfs(d+1, s+c[n], n+1);
    return 0;
}

int main(){
    cin >> N;
    dfs(0,"",0);
    return 0;
}