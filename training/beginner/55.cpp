#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll A[100001];
deque<ll> v;

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    v.push_back(A[0]);
    for(int i=1;i<N;i++){
        auto itr = lower_bound(v.begin(),v.end(),A[i]);
        if(itr == v.begin()) v.push_front(A[i]);
        else *(itr-1) = A[i];
    }
    cout << v.size() << endl;
    return 0;
}