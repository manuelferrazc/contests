#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007;
string n;
int d;

// dp[i][j][k] -> i indice, j -> mod d, k -> se tá igual a k
ll dp[10'001][100][2];

ll ddp(int i, int j, int k) {
    if(dp[i][j][k]!=-1) return dp[i][j][k];

    if(i==(int)n.size()) {
        if(j) return dp[i][j][k] = 0;
        else return dp[i][j][k] = 1;
    }

    dp[i][j][k] = 0;

    if(k) {
        for(char c='0';c<n[i];c++) dp[i][j][k]+=ddp(i+1,(j+(c-'0'))%d,0);
        dp[i][j][k]+=ddp(i+1,(j+n[i]-'0')%d,1);
    } else {
        for(char c='0';c<='9';c++) dp[i][j][k]+=ddp(i+1,(j+(c-'0'))%d,0);
    }

    return dp[i][j][k]%=mod;
}

int main() { _
    cin >> n >> d;

    for(int i=0;i<=10'000;i++) for(int j=0;j<100;j++) dp[i][j][0] = dp[i][j][1] = -1;

    cout << (ddp(0,0,1)-1+mod)%mod << '\n';

    return 0;
}
