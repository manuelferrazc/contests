#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll a,b;
    cin >> a >> b;

    ll k = b/a;

    if(a==1) cout << b*b << '\n';
    // else if(b%a==0) cout << 2*b << '\n';
    else if(gcd(a,b)==1) cout << a*b << '\n';
    else if(a*k==b and b%a==0) cout << b*k << '\n';
    else cout << b*(a/gcd(a,b)) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
