#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll m = 1'000'000'007;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n),b(n);

    for(ll &i:a) cin >> i;
    for(ll &i:b) cin >> i;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    ll ans=1,it=0;

    for(ll i=0;i<n;i++) {
        while(it<n and b[it]<a[i]) it++;
        ans = (ans*(it-i))%m;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
