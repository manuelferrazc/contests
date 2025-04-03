#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;
    vector<ll> c(n),r(n);

    multiset<ll> l;
    ll ans=0;
    for(int i=0;i<n;i++) {
        cin >> ans;
        l.insert(ans);
    }
    for(ll &i:r) cin >> i;
    for(ll &i:c) cin >> i;
    sort(r.begin(),r.end());
    vector<ll> v(n);
    for(int i=0;i<n;i++) {
        auto a = l.upper_bound(r[i]);
        a--;
        v[i] = r[i]-*a;
        l.erase(a);
    }
    
    sort(v.begin(),v.end());
    sort(c.rbegin(),c.rend());
    ans=0;
    for(int i=0;i<n;i++) ans+=c[i]*v[i];

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
