#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    // dp[i][0] -> batendo com o anterior
    // dp[i][1] -> nao batendo com o anterior
    
    // vou mudar a0 para a1, logo n tem q preocupar com a0
    vector<ll[2]> dp(n);
    vector<ll[2]> val(n);
    dp[1][0] = abs(v[1]-v[0]);
    dp[1][1] = 1e16;
    val[0][0] = val[0][1] = v[1];
    val[1][0] = v[1];
    val[1][1] = v[1];
    

    for(int i=2;i<n;i++) {
        dp[i][0] = min(dp[i-1][0]+abs(v[i]-val[i-1][0]),dp[i-1][1]+abs(v[i]-v[i-1]));
        // dp[i][0]+=abs(v[i]-v[i-1]);
        if(dp[i][0]==dp[i-1][0]+abs(v[i]-v[i-1])) val[i][0] = val[i-1][0];
        else val[i][0] = v[i-1];

        dp[i][1] = min({dp[i-1][0],// ok
                        dp[i-2][1]+abs(v[i-2]-v[i-1]),//ok
                        dp[i-2][0]+abs(val[i-2][0]-v[i-1])
                    });

        val[i][1] = v[i-1];
    }

    // ll ans = min({dp[n-2][0]+abs(v[n-2]-v[n-1]),
    //               dp[n-2][0]+abs(v[n-1]-v[1]),
    //               dp[n-2][1]+abs(v[n-1]-v[n-2])});
    ll ans = min(dp[n-1][0],dp[n-2][0]+abs(v[n-1]-v[1]));

    for(int i=1;i<n;i++) cout << dp[i][0] << ' ';
    cout << '\n';
    for(int i=1;i<n;i++) cout << dp[i][1] << ' ';
    cout << '\n';
    
    // agora nao vou mudar a0 para a1, entao tem q acertar no final
    dp[1][0] = 1e16;
    dp[1][1] = 0;
    val[1][0] = val[1][1] = v[1];
    val[0][0] = val[0][1] = v[0];


    for(int i=2;i<n;i++) {
        dp[i][0] = min(dp[i-1][0]+abs(v[i]-val[i-1][0]),dp[i-1][1]+abs(v[i]-v[i-1]));
        // dp[i][0]+=abs(v[i]-v[i-1]);
        if(dp[i][0]==dp[i-1][0]+abs(v[i]-v[i-1])) val[i][0] = val[i-1][0];
        else val[i][0] = v[i-1];

        dp[i][1] = min({dp[i-1][0],// ok
                        dp[i-2][1]+abs(v[i-2]-v[i-1]),//ok
                        dp[i-2][0]+abs(val[i-2][0]-v[i-1])
                    });

        val[i][1] = v[i-1];
    }

    cout << '\n';

    for(int i=1;i<n;i++) cout << dp[i][0] << ' ';
    cout << '\n';
    for(int i=1;i<n;i++) cout << dp[i][1] << ' ';
    cout << '\n';

    ans = min({ans,dp[n-2][0]+abs(v[0]-v[n-1]),dp[n-1][0]+abs(v[0]-val[n-1][0])});

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
