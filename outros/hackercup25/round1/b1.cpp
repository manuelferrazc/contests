#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,a,b;
    cin >> n >> a >> b;

    for(int i=1;i<2*n;i++) cout << 1 << ' ';
    cout << b << '\n';
}

int main() { _
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
