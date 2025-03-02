#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n,0);
    ll min = 1;

    for(ll i = k-1;i<n;i+=k) v[i] = min++;
    for(ll i=0;i<n;i++) if(not v[i]) v[i] = min++;

    for(ll i=0;i<n;i++) cout << v[i] << ' ';
    cout << '\n';
}

int main() { _
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
