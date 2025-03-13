#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll m,k,a1,ak;
    cin >> m >> k >> a1 >> ak;

    ll tk = m/k,t1=m%k;
    ll f1 = max(0LL,t1-a1), fk = max(0LL,tk-ak), r1=max(0LL,a1-t1);
    ll tr = min(r1/k,fk);
    cout << f1+fk-tr << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
