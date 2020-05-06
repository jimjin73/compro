#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N,M;
ll ac[100001], wa[100001];

int main(){
    cin >> N >> M;
    for(int i=0;i<=N;i++) ac[i] = wa[i] = 0;
    ll c_a, c_w;
    c_a = c_w = 0;
    for(int i=0;i<M;i++){
        ll p;
        string s;
        cin >> p;
        cin >> s;
        if(s == "AC"){
            if(ac[p] == 0) c_a++; 
            ac[p]++;
        }else{
            if(ac[p] == 0) wa[p]++;
        }
    }
    for(int i=0;i<=N;i++){
        if(ac[i] == 0) continue;
        c_w += wa[i];
    }
    cout << c_a << " " << c_w << endl;
    return 0;
}