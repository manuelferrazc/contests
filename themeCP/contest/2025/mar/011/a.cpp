#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int a,b,c;
    cin >> a >> b >> c;
    
    cout << ((b&1)==(c&1)) << ' ' << ((a&1)==(c&1)) << ' ' << ((a&1)==(b&1)) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
