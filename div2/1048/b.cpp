#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,m;
    cin >> n >> m;

    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    sort(v.begin(),v.end());

    ll ans = 0;
    ll qtd = m;
    ll suf = 0;
    for(ll i=n-1;i>=0 and qtd;i--,qtd--) {
        ans = max(ans,suf+v[i]*qtd);
        suf+=v[i]*qtd;
    }
    
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
