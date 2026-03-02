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

    set<ll> s;
    ll v[n];
    cin >> v[0];

    ll mx = v[0];
    ll mi = v[0];
    s.insert(v[0]);

    if(n==1) {
        cout << 1 << '\n';
        return;
    }

    for(int i=1;i<n;i++) {
        cin >> v[i];
        mx = max(mx,v[i]);
        mi = min(mi,v[i]);

        s.insert(v[i]);
    }

    sort(v,v+n);

    ll x = 0;
    for(int i=1;i<n;i++) x = gcd(v[i]-v[i-1],x);

    mx+=x;

    ll ans = 0;
    for(int i=0;i<n;i++) {
        ll d = mx-v[i];
        ans+=d/x;
    }

    for(ll i=mx-x;i>=mi-x;i-=x) {
        if(s.find(i)==s.end()) {
            ans = min(ans,ans-n+(mx-x-i)/x);
            break;
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
