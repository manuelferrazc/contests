#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll fexpkkk(ll n, ll e) {
    ll r=n;
    for(int i=1;i<e;i++) r*=n;
    return r;
}

void solve() {
    ll n;
    cin >> n;

    if(n<=9) {
        cout << n << '\n';
        return;
    }

    n-=9;

    ll q=2,e;
    while(true) {
        e = fexpkkk(10,q)-fexpkkk(10,q-1);
        if(e*q<n) {
            n-=e*q;
            q++;
        } else break;
    }
    ll p = n/q;
    if(n%q) p++;
    
    n = (n%q ? n%q-1 : q-1);

    cout << to_string(fexpkkk(10,q-1)+p-1)[n] << '\n';
}

int main() { _
    ll q;
    cin >> q;
    while(q--) solve();
    
    return 0;
}
