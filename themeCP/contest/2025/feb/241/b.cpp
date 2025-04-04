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
    if(m<n-1 or m>n*(n-1)/2) cout << "NO\n";
    else if(n==1 and k>=2) cout << "YES\n";
    else if(k<=2) cout << "NO\n";
    else if(k==3 and m<n*(n-1)/2) cout << "NO\n";
    else cout << "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
