#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    sort(v.begin(),v.end());

    vector<ll> g;
    for(int i=1;i<n;i++) {
        if(gcd(v[0],v[i])==v[0]) g.push_back(v[i]);
    }
    if(g.empty()) cout << "No\n";
    else {
        ll gg=g.front();
        for(ll i:g) gg = gcd(gg,i);

        if(gg!=v.front()) cout << "No\n";
        else cout << "Yes\n";
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
