#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll hur, pow, fim;
    cin >> hur >> pow >> fim;

    vector<pair<ll,ll>> h(hur);
    for(ull i=0;i<h.size();i++) cin >> h[i].ff >> h[i].ss;

    // ff = pos, ss = val
    vector<pair<ll,ll>> p(pow);
    for(ull i=0;i<p.size();i++) cin >> p[i].ff >> p[i].ss;

    multiset<ll> np;
    ll act = 1;
    hur = pow = 0;
    ll pulo = 1;
    ll ans=0;

    while(hur!=h.size()) {
        act = h[hur].ff-1;
        for(;pow<p.size() and p[pow].ff<=act;pow++) np.insert(p[pow].ss);

        while(act+pulo<=h[hur].ss) {
            if(np.size()) {
                pulo+=*np.rbegin();
                np.erase(prev(np.end()));
                ans++;
            }
            else {
                cout << "-1\n";
                return;
            }
        }
        hur++;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
