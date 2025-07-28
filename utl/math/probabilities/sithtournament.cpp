#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;
double prob[18][18];

double dp[18][1<<18];

double ddp(int p, int mask) {
    if(dp[p][mask]>-0.5) return dp[p][mask];

    dp[p][mask] = 0;
    for(int i=0;i<n;i++) {
        if(mask&(1<<i)) continue;
        dp[p][mask]+=ddp(p,mask|(1<<i))*prob[p][i];
        // dp[p][mask] = max(dp[p][mask],ddp(p,mask|(1<<i))*prob[p][i]);// esse já ganhou um e vai lutar dnv 
        // dp[p][mask] = max(dp[p][mask],ddp(i,mask|(1<<i))*prob[p][i]);// quem ganhou foi o outro, mas o outro perde agr 
    }

    return dp[p][mask];
}

int main() { _
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> prob[i][j];

    for(int i=0;i<n;i++) for(int j=0;j<(1<<n);j++) dp[i][j] = -1;
    for(int i=0;i<n;i++) dp[i][(1<<n)-1] = 1;


    cout << fixed << setprecision(10) << ddp(0,1) << '\n';

    return 0;
}
