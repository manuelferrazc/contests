#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll getsum(vector<ll> &sp, ll l, ll r) {
    if(l) return sp[r]-sp[l-1];
    return sp[r];
}

int main() { _
    ll n;
    cin >> n;
    vector<ll> v(n),sp(n);
    for(ll &i:v) cin >> i;
    
    sp[0] = v[0];
    for(ll i=1;i<n;i++) sp[i] = v[i]+sp[i-1];

    vector<vector<ll>> dp(n,vector<ll>(n));
    for(ll i=0;i<n;i++) dp[i][i] = v[i];

    for(ll l=n-2;l>=0;l--) {
        for(ll r=l+1;r<n;r++) {
            dp[l][r] = max(v[l]+getsum(sp,l+1,r)-dp[l+1][r],v[r]+getsum(sp,l,r-1)-dp[l][r-1]);
        }
    }

    cout << dp[0][n-1] << '\n';
    
    return 0;
}
