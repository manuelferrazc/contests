#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,h,k;
    cin >> n >> h >> k;

    int v[n];
    cin >> v[0];
    ll sp[n]; // prefix sum
    int mp[n], ms[n]; // prefix min, sufix max
    sp[0] = mp[0] = v[0];
    for(int i=1;i<n;i++) {
        cin >> v[i];
        sp[i] = sp[i-1]+v[i];
        mp[i] = min(mp[i-1],v[i]);
    }

    ms[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--) ms[i] = max(ms[i+1],v[i]);

    ll rem = h%sp[n-1];
    if(rem==0) {
        cout << (k+n)*(h/sp[n-1])-k << '\n';
        return;
    }

    ll l = 0, r = n-2;
    ll x = n-1;

    while(l<=r) {
        ll m = (l+r)/2;
        ll qtd = sp[m];
        if(mp[m]<ms[m+1]) {
            qtd-=mp[m];
            qtd+=ms[m+1];
        }

        if(qtd>=rem) {
            x = m;
            r = m-1;
        } else l = m+1;
    }

    ll ans = (k+n)*(h/sp[n-1]);

    cout << ans+x+1 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
