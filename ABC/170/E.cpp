#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,Q;
ll A[200000];
ll B[200000];
ll C[200000];
ll D[200000];
map<ll,ll> m[200000];
map<ll,ll> s;

int main(){
    cin >> N >> Q;
    for(int i=0;i<N;i++) cin >> A[i] >> B[i];
    for(int i=0;i<N;i++){
        B[i]--;
    }
    for(int i=0;i<Q;i++) cin >> C[i] >> D[i];
    for(int i=0;i<Q;i++){
        C[i]--;
        D[i]--;
    }
    for(int i=0;i<N;i++){
        m[B[i]][A[i]]++;
    }
    for(int i=0;i<200000;i++){
        if(m[i].size()==0) continue;
        auto p = m[i].rbegin();
        s[(*p).first]++;
    }
    for(int i=0;i<Q;i++){
        ll qq;
        ll a = A[C[i]];
        ll b = B[C[i]];
        auto p = m[b].rbegin();
        ll q = (*p).first;
        if(m[b][a] > 1) m[b][a]--;
        else m[b].erase(a);
        if(m[b].size()>0){
            p = m[b].rbegin();
            qq = (*p).first;
            if(q != qq){
                if(s[q] > 1) s[q]--;
                else s.erase(q);
                s[qq]++;
            }
        }else{
            if(s[q] > 1) s[q]--;
            else s.erase(q);
        }
        ll d = D[i];
        B[C[i]] = d;
        p = m[d].rbegin();
        if(m[d].size() > 0){
            q = (*p).first;
            m[d][a]++;
            p = m[d].rbegin();
            qq = (*p).first;
            if(q != qq){
                if(s[q] > 1) s[q]--;
                else s.erase(q);
                s[qq]++;
            }
        }else{
            m[d][a]++;
            p = m[d].rbegin();
            qq = (*p).first;
            s[qq]++;
        }
        auto ans = s.begin();
        cout << (*ans).first << endl;
    }
    return 0;
}