#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int K,T;
vector<P> A;

int main(){
    cin >> K >> T;
    for(int i=0;i<T;i++){
        int a;
        cin >> a;
        A.push_back({a,i});
    }
    int before = -1;
    int ans = 0;
    for(int i=0;i<K;i++){
        sort(A.rbegin(),A.rend());
        if(before != A[0].second){
            (A[0].first)--;
            before = A[0].second;
            continue;
        }
        if(A[1].first > 0){
            (A[1].first)--;
            before = A[1].second;
            continue;
        }
        ans = A[0].first;
        break;
    }
    cout << ans << endl;
    return 0;
}