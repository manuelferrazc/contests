#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct t{
    ll soma,qtd;
    t(ll _soma,ll _qtd): soma(_soma),qtd(_qtd) {}
};

t foo2(ll l,ll r,ll k) {
    ll s = r-l+1, m=(l+r)/2LL;
    if(s<k) return t(0,0);

    auto x = foo2(l,m-(s&1? 1 : 0),k);
    x.soma = 2*x.soma+m*(x.qtd+(s&1));
    x.qtd = x.qtd*2+(s&1);
    return x;
}

void solve() {
    ll n,k;
    cin >> n >> k;
    cout << foo2(1,n,k).soma << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
