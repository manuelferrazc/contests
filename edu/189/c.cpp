#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int solve() {
    int n;
    string a,b;
    cin >> n >> a >> b;
    
    int dp[n];
    dp[0] = a[0]!=b[0];

    if(n==1) return dp[0];

    dp[1] = 0;
    if(a[0]!=a[1]) dp[1]++;
    if(b[0]!=b[1]) dp[1]++;

    dp[1] = min(dp[1],(a[0]!=b[0])+(a[1]!=b[1]));

    for(int i=2;i<n;i++) {
        dp[i] = min(
            dp[i-1]+(a[i]!=b[i]), // botei em pé
            dp[i-2]+(a[i-1]!=a[i])+(b[i-1]!=b[i]) // botei 2 deitados
        );
    }

    return dp[n-1];
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
