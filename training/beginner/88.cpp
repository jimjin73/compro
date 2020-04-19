#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll A[100001];
deque<ll> v;

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    ll now = A[0];
    for(int i=1;i<N;i++){
        if(i % 2 == 0){
            if(A[i] == now) continue;
            now = A[i];
            v.push_back(i);
        }else{
            if(A[i] == now) continue;
            now = A[i];
            if(v.size() > 0) v.pop_back();
        }
    }
    ll sum = 0;
    if(v.size() > 0){
        if(v[0] != 0) v.push_front(0);
    }else{
        v.push_front(0);
    }
    for(int i=1;i<v.size();i++){
        if(A[v[i]] == 1) sum += v[i] - v[i-1];
    }
    if(now == 0){
        sum += N - v[v.size()-1];
    }
    cout << sum << endl;
    return 0;
}