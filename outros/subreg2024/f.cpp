#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin >> n;

    vector<ll> v(n+1);
    v[1] = 1;
    v[2] = 2;

    for(ll i=3;i<=n;i++) v[i] = v[i-1]+v[i-2];

    cout << v.back() << '\n';
    return 0;
}