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

    k = k/n + (k%n!=0);

    if(k==m) cout << m << '\n';
    else cout << m/(m-k+1) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
