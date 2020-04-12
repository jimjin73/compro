#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
int A[30001];
vector<int> v;

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    v.push_back(A[0]);
    for(int i=1;i<N;i++){
        auto itr = lower_bound(v.begin(),v.end(),A[i]);
        if(itr != v.end()){
            *itr = A[i];
        }else{
            v.push_back(A[i]);
        }
    }
    cout << N - v.size() << endl;
    return 0;
}