#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,a,b;
    cin >> n >> a >> b;
    a=gcd(a,b);

    vector<ll> v(n);
    for(auto &i:v) {
        cin >> i;
        i%=a;
    }

    sort(v.begin(),v.end());

    ll m = v.back()-v.front();

    for(ll j=1;j<n;j++) m=min(m,v[j-1]+a-v[j]);

    cout << m << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
