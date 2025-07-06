#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,ans=1;
    cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    bool b = true;
    while(b) {
        b = false;
        for(ll i=1;i<n;i++) {
            if(v[i]%v[i-1]==0) continue;
            // cout << "iii: " << i << ' ' << v[i] << ' ';
            b = true;
            v[i]*=ans;
            if(v[i]%v[i-1]) {
                v[i]/=ans;
                ll g=gcd(v[i-1],v[i]);
                // cout << i <<' ' << ans << ' ';
                ans=lcm(ans,v[i-1]/g);
                // cout << ans << ' ';
                v[i]*=ans;
            }
        
        // cout << v[i] << '\n';
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
