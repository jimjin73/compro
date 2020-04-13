#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
string s;
vector<ll> v[3];

int main(){
    cin >> N;
    cin >> s;
    for(int i=0;i<N;i++){
        if(s[i] == 'R') v[0].push_back(i);
        if(s[i] == 'G') v[1].push_back(i);
        if(s[i] == 'B') v[2].push_back(i);
    }
    ll sum = 0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(s[i] == s[j]) continue;
            ll diff = j - i;
            ll index = -1;
            if((s[i] == 'R' || s[i] == 'G') && (s[j] == 'R' || s[j] == 'G')){
                index = 2;
            }
            if((s[i] == 'R' || s[i] == 'B') && (s[j] == 'R' || s[j] == 'B')){
                index = 1;
            }
            if((s[i] == 'B' || s[i] == 'G') && (s[j] == 'B' || s[j] == 'G')){
                index = 0;
            }
            auto itr = upper_bound(v[index].begin(),v[index].end(),j);
            sum += v[index].end() - itr;
            if(binary_search(v[index].begin(),v[index].end(),j + diff)) sum--;
        }
    }
    cout << sum << endl;
    return 0;
}