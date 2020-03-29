#include <iostream>
#include <string>
#include <bitset>

using namespace std;
typedef long long ll;

int H,W,K;
string s[10];

int power(int n){
    int t = 1;
    for(int i=0;i<n;i++) t *= 2;
    return t;
}

int main(){
    cin >> H >> W >> K;
    for(int i=0;i<H;i++){
        cin >> s[i];
    }
    int mincut = 1e8;
    for(int i=0;i<power(H-1);i++){
        int cutnum = 0;
        bitset<9> bt(i);
        int team[10];
        team[0] = cutnum;
        for(int j=1;j<H;j++){
            if(bt[j-1]) cutnum++;
            team[j] = cutnum;
        }
        int counter[10];
        int mem[10];
        bool outflag = false;
        for(int t=0;t<10;t++) mem[t] = 0;
        for(int j=0;j<W;j++){
            bool cutflag = false;
            for(int t=0;t<10;t++) counter[t] = 0;
            for(int k=0;k<H;k++){
                if(s[k][j] == '1') counter[team[k]]++;
            }
            for(int t=0;t<10;t++){
                if(counter[t] > K) outflag = true;
            }
            if(outflag) break;
            for(int t=0;t<10;t++){
                if(mem[t] + counter[t] > K) cutflag = true;
            }
            if(cutflag){
                cutnum++;
                for(int t=0;t<10;t++) mem[t] = counter[t];
            }else{
                for(int t=0;t<10;t++) mem[t] += counter[t];
            }
        }
        if(outflag) continue;
        if(cutnum < mincut) mincut = cutnum;
    }
    cout << mincut << endl;
    return 0;
}