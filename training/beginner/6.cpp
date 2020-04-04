#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
int N;
vector<int> v[10];

int main(){
    cin >> N;
    cin >> s;
    for(int i=0;i<s.size();i++){
        v[s[i]-'0'].push_back(i);
    }
    int c = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                if(v[i].size()==0) continue;
                int f = v[i][0];
                auto s_itr = upper_bound(v[j].begin(), v[j].end(), f);
                if(s_itr == v[j].end()) continue;
                int s = *s_itr;
                auto t_itr = upper_bound(v[k].begin(), v[k].end(), s);
                if(t_itr == v[k].end()) continue;
                c++;
            }
        }
    }
    cout << c << endl;
    return 0;
}