#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n, x;
    cin >> n;
    multiset<ll> s,ns;
    cin >> x;
    s.insert(x);
    cout << '1' << ' ';
    
    for(ll i=2;i<=n;i++) {
        cin >> x;
        ns.insert(*s.begin());
        s.erase(s.begin());
        s.insert(x);
        while(ns.size() and *ns.rbegin()>s.size()) {
            s.insert(*ns.rbegin());
            ns.erase(prev(ns.end()));
        }
        cout << s.size() << ' ';
    }
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
