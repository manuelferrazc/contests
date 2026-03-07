#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    ll n,ans=0;
    cin >> n;

    set<ll> s;
    ll mx = LLONG_MAX;

    ll sq = sqrt(n);

    for(ll i=1;i<=sq;i++) {
        ans+=i*(n/i)*2;

        // ll d = n/i;
    }

    // ans+= sq*(n/sq);

    cout << ans << '\n';

    return 0;
}
