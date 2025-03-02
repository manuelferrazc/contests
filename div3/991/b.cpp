#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin >> v[i];

    ll si=0,sp=0;
    for(ll i=0;i<n;i++) {
        if(i&1) sp+=v[i];
        else si+=v[i];
    }

    ll np = n/2, ni = n/2+(n&1);

    if(sp%np or si%ni or (sp/np)!=(si/ni)) cout << "NO\n";
    else cout << "YES\n";
}

int main() { _
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
