#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n,ans=LLONG_MIN,act = 0;
    cin >> n;

    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    for(ll &i:v) {
        act+=i;
        ans = max(ans,act);
        act = max(0LL,act);
    }

    cout << ans << '\n';

    return 0;
}
