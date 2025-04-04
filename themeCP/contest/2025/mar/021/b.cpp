#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    // a/b = c/d -> ad=bc

    if(a*d==b*c) cout << 0 << '\n';
    else if((c and (a*d)%(b*c)==0) or (a and (b*c)%(a*d)==0)) cout << 1 << '\n';
    else cout << 2 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
