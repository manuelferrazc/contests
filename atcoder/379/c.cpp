#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n,m;
    cin >> n >> m;
    vector<ll> x(m), a(m);
    for(auto &i : x) cin >> i;
    for(auto &i: a) cin >> i;

    if(x[0]!=1) {
        cout << "-1\n";
        return 0;
    }

    x.push_back(n);
    a.push_back(0);
    ll ans=0;
    for(ll i=0;i<m;i++) {
        ll qtd = x[i+1]-x[i];
        if(a[i]<qtd) {
            cout << "-1\n";
            return 0;
        }
        a[i+1]+=a[i]-qtd;
        ans+=(a[i]-qtd+1)*(qtd+1)/2;
    }

    if(a.back()!=1) cout << "-1\n";
    else cout << ans << '\n';

    // for(int i=0;i<=m;i++) {
    //     cout << x[i] << ' ' << a[i] << endl;
    // }
    return 0;
}
