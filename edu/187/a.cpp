#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m,d;
    cin >> n >> m >> d;

    int mx = d/m; // quantas caixas podem ter

    cout << n/(mx+1) + (n%(mx+1)!=0) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
