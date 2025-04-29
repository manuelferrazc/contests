#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    ll m = *max_element(v.begin(),v.end());

    string s;
    ll l, r;
    while(q--) {
        cin >> s >> l >> r;

        if(l<=m and m<=r) {
            if(s[0]=='+') m++;
            else m--;
        }

        cout << m << ' ';
    }
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
