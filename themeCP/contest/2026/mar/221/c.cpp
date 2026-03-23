#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<ll> v(n+1,0);
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        v[x]++;
    }

    ll ans = 0;

    for(int i=n;i>=0;i--) {
        n-=v[i];

        if(v[i]<=1) continue;
        
        if(v[i]>=3) ans += (v[i]*(v[i]-1)*(v[i]-2))/6;
        ans += (v[i]*(v[i]-1)/2)*n;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
