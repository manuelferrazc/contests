#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n = 1'000'001;

int main() { _
    vector<ll> dp1(n),dp2(n);
    dp1[1] = dp2[1] = 1;
    
    const ll mod = 1'000'000'007LL;

    for(ll i=2;i<n;i++) {
        dp1[i]=dp1[i-1]*dp1[i-1];
        dp2[i]=dp2[i-1]+dp1[i-1]+1;
    }

    cin >> n;

    while(n--) {
        ll x;
        cin >> x;
        cout << (dp1[x]+dp2[x])%mod << '\n';
    }

    return 0;
}
