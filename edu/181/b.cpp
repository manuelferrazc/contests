#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll a,b,k;
    cin >> a >> b >> k;

    if(max(a,b)<=k or a==b) cout << "1\n";
    else {
        ll g = gcd(a,b);
        if(a/g<=k and b/g<=k) cout << "1\n";
        else cout << "2\n";
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
