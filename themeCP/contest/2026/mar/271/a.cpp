#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,x,y;
    cin >> n >> x >> y;

    ll v[n];
    ll t = 0;
    
    for(int i=0;i<n;i++) {
        cin >> v[i];
        t+=v[i]/x;
    }

    ll ans = 0;
    for(int i=0;i<n;i++) {
        ans = max(ans,v[i]+ (t-v[i]/x)*y);
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
