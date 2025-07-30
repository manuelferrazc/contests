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
    if(mask==(1<<n)-1) {
        if(p==0) return dp[p][mask] = 1;
        else return dp[p][mask] = 0;
    }

    double a=0;
    for(int i=0;i<n;i++) {
        if(mask&(1<<i)) continue;
        a = max(a,ddp(p,mask|(1<<i))*prob[p][i]+ddp(i,mask|(1<<i))*prob[i][p]);
    }

    return dp[p][mask] = a;
}

int main() { _
    cin >> n;
    if(n==1) {
        cout << 1 << '\n';
        return 0;
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> prob[i][j];

    for(int i=0;i<n;i++) for(int j=0;j<(1<<n);j++) dp[i][j] = -1;
    
    double ans = 0;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) {
        ans = max(
            ans,
            ddp(i,(1<<i)|(1<<j))*prob[i][j]+ddp(j,(1<<i)|(1<<j))*prob[j][i]

        );
    }

    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}
