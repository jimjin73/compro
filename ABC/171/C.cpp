#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N;
vector<char> v;

int main(){
    cin >> N;
    while(N > 0){
        v.push_back('a' + ((N-1)%26));
        N -= (N-1)%26;
        N /= 26;
    }
    for(int i=v.size()-1;i>=0;i--) cout << v[i];
    cout << endl;
    return 0;
}