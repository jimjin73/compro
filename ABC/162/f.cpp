#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
ll A[200010];
unordered_map< ll , ll > um;

ll o(ll sp, ll ep){
    if(um.find(sp*200000+ep) != um.end()) return um[sp*200000+ep];
    if(um.find((sp-2)*200000+(ep+2)) != um.end()){
        return um[sp*200000+ep] = um[(sp-2)*200000+(ep+2)] - A[sp-2] - A[sp-1] - A[ep+1] - A[ep-2];
    }
    ll sum = 0;
    for(int i=sp;i<ep;i+=2){
        sum += A[i];
    }
    return um[200000*ep] = sum; 
}

ll even(ll sp, ll ep){
    ll sum_a, sum_b,sum_c;
    if(ep-sp==2) return max(A[sp],A[sp+1]);
    if(sp == ep) return 0;
    sum_a = o(sp,ep-1);
    sum_b = o(sp+1,ep);
    sum_c = even(sp+2, ep-2) + A[sp] + A[ep-1];
    return max(max(sum_a,sum_b),sum_c);
}

ll odd(ll sp, ll ep){
    if(ep - sp == 3) return max(A[sp],max(A[sp+1],A[sp+2]));
    if(ep - sp == 1) return 0;
    ll sum_a,sum_b;
    sum_a = A[sp] + odd(sp+2,ep);
    sum_b = even(sp+1,ep);
    return max(sum_a,sum_b);
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    if(N%2 == 0) cout << even(0,N) << endl;
    else cout << odd(0,N) << endl;
    return 0;
}