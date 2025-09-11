#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9+7;

void solve() {
    int n,m;
    string s,t;
    cin >> n >> m >> s >> t;

    ll dp[n+1][m+1][2];
    for(ll i=0;i<=n;i++) for(ll j=0;j<=m;j++) dp[i][j][0] = dp[i][j][1] = 0;
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;

    for(int i=1;i<=n;i++) {
        dp[i][0][1] = (dp[i-1][0][1]+dp[i-1][0][0]*25)%mod;
        dp[i][0][0] = 1;
        for(int j=1;j<=min(i,m);j++) {
            if(s[i-1]==t[j-1]) {
                // ou ignoro (podendo mudar ou n), ou eu uso
                dp[i][j][1] = (dp[i-1][j][1]+25*dp[i-1][j][0]+dp[i-1][j-1][1])%mod;
                // ou eu ignoro ou uso (n posso mudar nunca)
                dp[i][j][0] = (dp[i-1][j][0]+dp[i-1][j-1][0])%mod;// ok
            } else {
                // ou eu mudo e caso, ou ignoro (podendo mudar ou n)
                dp[i][j][1] = (dp[i-1][j-1][0]+dp[i-1][j][1]+dp[i-1][j][0]*25)%mod;
                dp[i][j][0] = dp[i-1][j][0]; // ok
            }
        }
    }

    // cout << "Podendo mudar: \n";
    // for(int j=0;j<=m;j++) {
    //     for(int i=0;i<=n;i++) cout << dp[i][j][1] << ' ';
    //     cout << '\n';
    // }

    // cout << "Não podendo mudar: \n";
    // for(int j=0;j<=m;j++) {
    //     for(int i=0;i<=n;i++) cout << dp[i][j][0] << ' ';
    //     cout << '\n';
    // }

    cout << dp[n][m][1] << '\n';

    return;
}

int main() { _
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
