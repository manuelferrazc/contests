#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n,m,k;

bool ok(ll a, ll b) {
    if(a>b) swap(a,b);

    ll qtd;
    if(a==0) qtd = 2*b-1;
    else qtd = a-1+a+(b-a)+b;

    return qtd<=m;
}

void solve() {
    cin >> n >> m >> k;

    ll ans = 1;
    for(int i=0;i+k<=n;i++) {
        ll l=0,r=k-1;
        if(not ok(0,i)) break;

        while(l<=r) {
            ll m2 = (l+r)>>1;
            if(ok(i,m2)) {
                ans = max(ans,i+m2+1);
                l = m2+1;
            } else r = m2-1;
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
