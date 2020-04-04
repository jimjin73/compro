#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;

int main(){
    cin >> s;
    int n = s.size();
    int max_len = 0;
    for(int i=0;i<n;i++){
        for(int j=1;i+j<=n;j++){
            string ss = s.substr(i,j);
            /*
            bool flag = true;
            for(const auto& e : ss){
                if(e != 'A' && e != 'C' && e != 'G' && e != 'T'){
                    flag = false;
                }
            }
            if(flag && max_len < j) max_len = j;
            */
            int c = 0;
            c += count(ss.begin(), ss.end(), 'A');
            c += count(ss.begin(), ss.end(), 'C');
            c += count(ss.begin(), ss.end(), 'G');
            c += count(ss.begin(), ss.end(), 'T');
            if(c == j && max_len < j) max_len = j;
        }
    }
    cout << max_len << endl;
    return 0;
}