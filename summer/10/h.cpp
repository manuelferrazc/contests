#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pr first
#define gr second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    ll n,s;
    cin >> n >> s;
    
    pair<ll,ll> p[n];
    
    for(int i=0;i<n;i++) cin >> p[i].pr;
    for(int i=0;i<n;i++) cin >> p[i].gr;

    sort(p,p+n,[](pair<ll,ll> const &a, pair<ll,ll> const &b) -> bool {
        return a.gr>b.gr;
    });

    ll dp[1900];
    dp[0] = 0;
    dp[1] = p[0].pr;
    for(int i = 2;i<1900;i++) dp[i] = LLONG_MAX;

    for(int i=1;i<n;i++) {
        for(int j=1899;j;j--) {
            if(dp[j-1]!=LLONG_MAX) dp[j] = min(dp[j-1]+p[i].pr+p[i].gr*(j-1),dp[j]);
        }
    }

    for(int i=1899;i>=0;i--) {
        if(dp[i]<=s) {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
