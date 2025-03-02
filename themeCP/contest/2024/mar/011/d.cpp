#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,m;
    cin >> n >> m;

    ll ans=0;
    for(ll b=1;b<=m;b++) 
        for(ll a=b;a<=n;a+=b) if((a+b)%(b*gcd(a,b))==0) ans++;

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
