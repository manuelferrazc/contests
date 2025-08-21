#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

auto solve() {
    ll n,k;
    cin >> n >> k;

    vector<ll> s(n),t(n);
    for(ll &i:s) cin >> i;
    for(ll &i:t) cin >> i;

    map<ll,ll> c;
    for(ll i=0;i<n;i++) c[s[i]%k]++;

    for(ll i=0;i<n;i++) {
        if(c.count(t[i]%k)) {
            c[t[i]%k]--;
            if(c[t[i]%k]==0) c.erase(t[i]%k);
        } else if(c.count(abs(t[i]%k-k))) {
            c[abs(t[i]%k-k)]--;
            if(c[abs(t[i]%k-k)]==0) c.erase(abs(t[i]%k-k));
        } else return "NO\n";
    }

    return "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
