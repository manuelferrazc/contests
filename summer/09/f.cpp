#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool ok(int *v2, int n, ll h, ll d) {
    ll im = (d+1)/2;
    ll p = d-im;

    int v[n];
    for(int i=0;i<n;i++) {
        v[i] = v2[i];

        ll dif = h-v[i];
        dif/=2;

        v[i]+=min(2*p,2*dif);

        p-=min(p,dif);
    }

    for(int i=0;i<n;i++) {
        ll dif = h-v[i];

        if(dif>im) return false;
        im-=dif;
    }

    return true;
}

void solve() {
    int n;
    cin >> n;

    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    ll l = 0, r = 1'000'000'000'000'000ll;
    ll ans = LLONG_MAX;

    int mx = *max_element(v,v+n);

    while(l<=r) {
        ll m = (l+r)/2;

        if(ok(v,n,mx,m) or ok(v,n,mx+1,m)) {
            ans = m;
            r = m-1;
        } else l = m+1;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
