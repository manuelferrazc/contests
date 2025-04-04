#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll a,b,m;
    cin >> a >> b >> m;
    m++;

    cout << m/a + (m%a!=0) + m/b + (m%b!=0) << '\n';

}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
