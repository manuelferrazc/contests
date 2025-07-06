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
    ll b=v[0],m=v[0];
    for(ll i=1;i<n;i++) {
        m=min(m,v[i]);
        b+=m;
    }
    
    if(v[0]<=v[1]) {
        b = min(b,v[0]+v[1]);
        if(n>2) b = min(b,v[0]*2);
    } else {
        b = min(b,v[0]+v[1]);
        if(n>=3) b=min({b,v[0]+v[2]+v[1],v[0]+min(v[0],v[1]+v[2])});
    }

    cout << b << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
