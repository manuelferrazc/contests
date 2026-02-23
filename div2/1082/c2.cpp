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
    ll v[n];
    for(int i=0;i<n;i++) cin >> i[v];

    int rep[n];
    rep[0] = 1;

    ll start = v[0], mx = v[0];

    for(int i=1;i<n;i++) {
        if(start<v[i] and v[i]<=mx+1) {
            mx = v[i];
            rep[i] = 0;
        } else {
            start = v[i];
            mx = v[i];
            rep[i] = 1;
        }
    }

    ll ans = n;
    map<int,int> m;
    for(ll i=1;i<n;i++) {
        if(rep[i]) {
            ans+=(i+1)*(n-i);
            start = i;
        } else {
            auto it = m.find(v[i]-1);
            ans+=(i-it->ss)*(n-i);
        }

        m[v[i]] = i;
    }

    cout << ans << '\n';
}
    
int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
