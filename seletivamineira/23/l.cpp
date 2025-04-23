#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll count(vector<ll> &v) {
    ll n = v.size();
    vector<ll> sq(n),sp(n),sqp(n);
    for(ll i=0;i<n;i++) sq[i] = v[i]*v[i];

    sp[n-1] = v[n-1];
    sqp[n-1] = sq[n-1];

    for(ll i=n-2;i>=0;i--) {
        sp[i] = sp[i+1]+v[i];
        sqp[i] = sqp[i+1]+sq[i];
    }

    ll r = 0;

    for(ll i=0;i<n-1;i++) {
        r+=(n-i-1)*sq[i];
        r-=2*v[i]*(sp[i+1]);
        r+=sqp[i+1];
    }

    return r;
}

int main() { _
    ll n;
    cin >> n;
    vector<ll> x(n),y(n);
    for(ll i=0;i<n;i++) cin >> x[i] >> y[i];

    cout << count(x) + count(y) << '\n';
    return 0;
}
