#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * yes = "YES\n";
const char * no = "NO\n";

const char * solve() {
    ll n,m,a,b;
    cin >> n >> m >> a >> b;

    if(gcd(n,a)>1 or gcd(m,b)>1 or gcd(n,m)>2) return no;
    return yes;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
