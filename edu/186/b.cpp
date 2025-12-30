#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> qtd;

void solve() {
    ll a,b;
    cin >> a >> b;

    ll l=2,r=25;
    ll ans = 1;

    while(l<=r) {
        ll m = (l+r)>>1;

        if((qtd[m]<=a and qtd[m-1]<=b) or (qtd[m]<=b and qtd[m-1]<=a)) {
            ans = m;
            l = m+1;
        } else r = m-1;
    }

    cout << ans << '\n';
}

int main() { _
    qtd.push_back(0);
    qtd.push_back(1);
    qtd.push_back(2);

    for(int i=3;i<25;i++) {
        qtd.push_back(qtd[i-2]+(1<<(i-1)));
    }
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
