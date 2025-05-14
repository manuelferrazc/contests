#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n;
    cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    ll ans = LLONG_MAX;
    for(ll i=0;i<(1<<n);i++) {
        ll a=0,b=0;
        for(ll j=0;j<n;j++) {
            if(i&(1<<j)) a+=v[j];
            else b+=v[j];
        }

        ans = min(ans,abs(a-b));
    }

    cout << ans << '\n';

    
    return 0;
}
