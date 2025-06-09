#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool getsol(ll n, ll v1, ll v2, ll &x, ll &y) {
    y = -(v2-2*v1);
    if(y<0 or y%(n+1)) return false;
    y/=n+1;

    x = v1 - y*n;
    return x>=0;
}
        
void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    ll x,y;
    if(not getsol(n,v[0],v[1],x,y)) {
        cout << "NO\n";
        return;
    }

    for(ll i=2;i<n;i++) {
        if(x*(i+1)+y*(n-i)!=v[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
