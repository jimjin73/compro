#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

ll N,C;
vector<P> ch[30];
vector<P> v;
vector<ll> r;

int main(){
    cin >> N >> C;
    for(int i=0;i<N;i++){
        ll s,t,c;
        cin >> s >> t >> c;
        ch[c-1].push_back(make_pair(s,t));
    }
    for(int i=0;i<C;i++){
        if(ch[i].size()==0) continue;
        sort(ch[i].begin(),ch[i].end());
        ll s,t,ls,lt;
        ls = ch[i][0].first;
        lt = ch[i][0].second;
        for(int j=1;j<ch[i].size();j++){
            s = ch[i][j].first;
            t = ch[i][j].second;
            if(s != lt){
                v.push_back(make_pair(lt,ls));
                ls = s;
                lt = t;
            }else{
                lt = t;
            }
        }
        v.push_back(make_pair(lt,ls));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        ll s,t;
        s = v[i].second;
        t = v[i].first;
        ll ind = -1;
        ll t_max = -1;
        for(int j=0;j<r.size();j++){
            if(r[j] < s){
                if(t_max < r[j]){
                    ind = j;
                    t_max = r[j];
                }
            }
        }
        if(ind == -1) r.push_back(t);
        else r[ind] = t;
    }
    cout << r.size() << endl;
    return 0;
}