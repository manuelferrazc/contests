#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int x,y;
    cin >> x >> y;

    int l = abs(x-y);
    int ans = (l==0);

    for(int i=1;i<=l;i++) if(l%i==0) ans++;
    cout << ans << '\n';

    for(int i=0;i<x;i++) cout << 1 << ' ';
    for(int i=0;i<y;i++) cout << -1 << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
