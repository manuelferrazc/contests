#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll count(ll n) {
    ll q1,q2,q3,q4;

    q1 = n/2+n/3+n/5+n/7;
    q2 = n/6+n/10+n/14+n/15+n/21+n/35;
    q3 = n/30+n/42+n/70+n/105;
    q4 = n/210;

    return q1-q2+q3-q4;
}

void solve() {
    ll l,r;
    cin >> l >> r;

    cout << (r-l+1)-(count(r)-count(l-1)) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
