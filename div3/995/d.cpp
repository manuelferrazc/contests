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
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());

    ll ans=x, s = accumulate(v.begin(),v.end(),0LL);
    ll a=x,b=y;
    x=s-y;
    y=s-ans;
    ans=0;
    for(ll i=0;i<n;i++) {
        auto i1 = lower_bound(v.begin(),v.end(),x-v[i]);
        auto i2 = upper_bound(v.begin(),v.end(),y-v[i]);
        ans+=i2-i1;
    }
    
    for(ll i=0;i<n;i++) if(a<=s-2*v[i] and s-2*v[i]<=b) ans--;

    cout << ans/2 << '\n';
}

int main() { _
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
