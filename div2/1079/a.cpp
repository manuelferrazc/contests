#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll sum(ll x) {
    ll s=0;
    while(x) {
        s+=x%10;
        x/=10;
    }
    return s;
}

void solve() {
    ll n;
    cin >> n;

    int ans = 0;

    for(int i=0;i<200;i++) {
        ll y = n+i;
        if(y-sum(y)==n) ans++;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
