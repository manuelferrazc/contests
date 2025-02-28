#include <algorithm>
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
 
    ll ans = *max_element(v.begin(),v.end()),c=0;
    if(ans<0) {
        cout << ans << '\n';
        return;
    }

    for(ll i=0;i<n;i+=2) {
        if(v[i]>0) c+=v[i];
        ans=max(ans,c);
    }
 
    c=0;

    for(ll i=1;i<n;i+=2) {
        if(v[i]>0) c+=v[i];
        ans=max(ans,c);
    }
    
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
