#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int l,r,n,m;
    cin >> n >> m >> l >> r;
    while(r>0 and r-l>m) r--;
    while(l<0 and r-l>m) l++;
    cout << l << ' ' << r << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
