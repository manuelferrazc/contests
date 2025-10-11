#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll med(ll a, ll b, ll c) {
    if(a<=b and b<=c) return c-a;
    if(c<=b and b<=a) return a-c;

    if(a<=c and c<=b) return b-a;
    if(b<=c and c<=a) return a-b;

    if(b<=a and a<=c) return c-b;
    return b-c;
}

ll count(ll *v, int n) {
    ll dp[n+1][4];
    
    dp[0][2] = 0;
    dp[0][3] = 0;
    
    dp[1][2] = 1e16;
    dp[1][3] = 1e16;

    dp[2][2] = abs(v[2]-v[1]);
    dp[2][3] = 1e16;
    for(int i=3;i<=n;i++) {
        dp[i][2] = abs(v[i]-v[i-1])+min(dp[i-2][2],dp[i-2][3]);
        dp[i][3] = med(v[i],v[i-1],v[i-2])+min(dp[i-3][2],dp[i-3][3]);
    }

    return min(dp[n][2],dp[n][3]);
}

void solve() {
    int n;
    cin >> n;

    ll v[n+3];
    for(int i=1;i<=n;i++) cin >> v[i];
    v[n+1] = v[1];
    v[n+2] = v[2];

    ll ans = count(v,n);

    ans = min(ans,count(v+1,n));
    ans = min(ans,count(v+2,n));

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
