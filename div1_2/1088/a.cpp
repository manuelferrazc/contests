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

    int lx;
    for(int i=0;i<n;i++) cin >> lx;

    int ans = min(n,2);
    for(int i=0;i<n;i++) cout << ans << ' ';
    cout << '\n'; 
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
