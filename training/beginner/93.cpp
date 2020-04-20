#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int H,W,K;
int m[40][40];
int n[40][40];
string s[40];

void printn(){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout << n[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
}

int sc(int t){
    int score = 0;
    for(int i=0;i<H;i++){
        int now = 0;
        int l = 0;
        for(int j=0;j<W;j++){
            if(n[i][j] == 0){
                if(l >= K){
                    score += now * l;
                    for(int k=0;k<l;k++) n[i][j-1-k] = 0;
                }
                now = 0;
                l = 0;
                continue;
            }
            if(n[i][j] == now){
                l++;
                continue;
            }
            if(l >= K){
                score += now * l;
                for(int k=0;k<l;k++) n[i][j-1-k] = 0;
            }
            now = n[i][j];
            l = 1;
        }
        if(l >= K){
            score += now * l;
            for(int k=0;k<l;k++) n[i][W-1-k] = 0;
        }        
    }
    return score * t;
}

void fall(){
    for(int i=0;i<W;i++){
        vector<int> v;
        for(int j=H-1;j>=0;j--){
            if(n[j][i] != 0) v.push_back(n[j][i]);
        }
        for(int j=0;j<H;j++) n[j][i] = 0;
        for(int j=0;j<v.size();j++) n[H-1-j][i] = v[j];
    }
}

int calc(int h, int w){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            n[i][j] = m[i][j];
        }
    }
    n[h][w] = 0;
    //printn();
    fall();
    int score = 0;
    int turn = 1;
    while(true){
        //printn();
        int s = sc(turn);
        score += s;
        //printn();
        if(s == 0) break;
        fall();
        turn *= 2;
    }
    return score;
}

int main(){
    cin >> H >> W >> K;
    for(int i=0;i<H;i++) cin >> s[i];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            m[i][j] = s[i][j] - '0';
        }
    }
    int max_p = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            max_p = max(max_p, calc(i,j));
        }
    }
    cout << max_p << endl;
    return 0;
}