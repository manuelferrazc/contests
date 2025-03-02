#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,x,y;
    cin >> n >> x >> y;
    vector<int> v(n);
    for(auto &i:v) cin >> i;

    const ll s=accumulate(v.begin(),v.end(),0);
    ll ans=0;
    for(ll i=0;i<n;i++) {
        for(ll j=i+1;j<n;j++) {
            ll a = s-v[i]-v[j];
            if(x<=a and a<=y) ans++;
        }
    }
    cout << ans << '\n';
}

int main() { _
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
