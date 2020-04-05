#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
vector<int> v;
vector<int> p,q;

int main(){
    int t;
    cin >> N;
    for(int i=1;i<=N;i++) v.push_back(i);
    for(int i=0;i<N;i++){
        cin >> t;
        p.push_back(t);
    }
    for(int i=0;i<N;i++){
        cin >> t;
        q.push_back(t);
    }
    int a,b,i;
    i=0;
    do{
        if(p == v) a = i;
        if(q == v) b = i;
        i++;
    }while(next_permutation(v.begin(),v.end()));
    cout << abs(a-b) << endl;
    return 0;
}