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
    vector<ll> c(n);

    multiset<ll> l,r;
    ll ans=0;
    for(int i=0;i<n;i++) {
        cin >> ans;
        l.insert(ans);
    }
    for(int i=0;i<n;i++) {
        cin >> ans;
        r.insert(ans);
    }
    for(ll &i:c) cin >> i;

    vector<pair<ll,ll>> v(n);
    multimap<ll,pair<int,int>> m;
    for(int i=0;i<n;i++) {
        auto a = l.begin(), b = r.begin();
        m.insert({*b-*a,make_pair(*a,*b)});
        l.erase(a);
        r.erase(b);
    }

    sort(c.rbegin(),c.rend());
    ans=0;
    for(int i=0;i<n;i++) {
        auto it = m.begin();
        ans+=c[i]*(it->ff);
        m.erase(it);
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
