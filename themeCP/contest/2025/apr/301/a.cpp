#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n, ans=0;
    cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    
    ll a=0,b=0;
    while(a!=n and not v[a]) a++;
    if(a==n) {
        cout << 0 << '\n';
        return;
    }

    b=a;

    while(b<n-1) {
        if(v[b]) {
            b++;
            continue;
        } else {
            while(v[a]==0) a++;
            ans++;
            v[a]--;
            v[b]++;
            b++;
        }
    }

    while(a<n-1) {
        ans+=v[a];
        a++;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
