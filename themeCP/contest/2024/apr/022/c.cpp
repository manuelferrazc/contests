#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,m,k;
    cin >> n >> m >> k;
    if(k>3LL) cout << 0 << '\n';
    else if(k==1) cout << 1 << '\n';
    else if(k==2) {
        if(m>=n) cout << m/n-1+n << '\n';
        else cout << min(n,m) << '\n';
    } else {
        if(m>n) cout << m-n-(m/n-1) << '\n';
        else cout << 0 << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
