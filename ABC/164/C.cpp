#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

unordered_set<string> us;
ll N;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        if(us.count(s) > 0) continue;
        us.insert(s);
    }
    cout << us.size() << endl;
    return 0;
}