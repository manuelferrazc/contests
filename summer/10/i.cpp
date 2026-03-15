#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { 
    const int mod = 1'000'000'007;
    int n;
    cin >> n;

    // # de comp, # bordas, # meios
    ll dp[n+1][3][3];
    for(int j=0;j<=n;j++) {
        for(int k=0;k<9;k++) dp[j][k/3][k%3] = 0;
    }

    dp[1][2][0] = 1;
    // cout << "# bordas, # meios\n";
    // for(int k=0;k<9;k++) cout << k/3 << ' ' << k%3 << '\n';

    for(int i=1;i<n;i++) {
        ll dp2[n+1][3][3];

        for(int j=0;j<=n;j++) {
            for(int k=0;k<9;k++) dp2[j][k/3][k%3] = 0;
        }

        for(int j=1;j<=i+1;j++) { // # de comp
            // adicionar nas bordas
            dp2[j][1][0] += dp[j][1][0] + dp[j][1][1] + dp[j][1][2] + 2 * (dp[j][0][0]+dp[j][0][1]+dp[j][0][2]);

            // criar componente na borda
            for(int k=0;k<9;k++) dp2[j][1][1] += 2*dp[j-1][k/3][k%3];

            // criar componente no meio
            if(j>=3) for(int k=0;k<9;k++) dp2[j][0][2] += (j-2)*dp[j-1][k/3][k%3];

            for(int k=0;k<9;k++) dp2[j][0][1] += (2*j-2-(k%3))*dp[j][k/3][k%3];
            // for(int k=0;k<3;k++) dp2[j][0][1] += (2*j-2)*dp[j][k][0];
            // for(int k=0;k<3;k++) dp2[j][0][1] += (2*j-3)*dp[j][k][1];
            // for(int k=0;k<3;k++) dp2[j][0][1] += (j-2)*dp[j][k][2];

            // falta juntar componentes
            if(j<n) {
                for(int k=0;k<3;k++) dp2[j][0][0] += j*dp[j+1][k][0];
                for(int k=0;k<3;k++) dp2[j][0][0] += (j-1)*dp[j+1][k][1];
                for(int k=0;k<3;k++) dp2[j][0][0] += (j-2)*dp[j+1][k][2];
            }
        }

        // println("i = {}:",i+1);
        // for(int j=0;j<=n;j++) {
        //     for(int k=0;k<9;k++) cout << dp2[j][k/3][k%3] << ' ';
        //     cout << '\n';
        // }
        // cout << '\n';

        for(int j=0;j<=n;j++) {
            for(int k=0;k<9;k++) dp[j][k/3][k%3] = dp2[j][k/3][k%3]%mod;
        }
    }

    ll ans = 0;
    for(int k=0;k<9;k++) ans += dp[1][k/3][k%3];
    cout << ans%mod << '\n';

    return 0;
}
