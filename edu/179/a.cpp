#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    vector<ll> v(3,0);
    ll x,ans=1;
    cin >> x;
    v[2] = 1;
    while(v[0]<x) {
        ans++;
        v[0]=2*v[1]+1;
        sort(v.begin(),v.end());
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
