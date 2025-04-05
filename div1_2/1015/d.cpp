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

    vector<ll> v(n,-1LL);
    ll q = n/(m+1);
    
    for(ll i=0;i<q;i++) {
        ll qtd=0,j;
        for(j=i;j<n and qtd<=m;j+=max(k,q),qtd++) v[j] = i;
        if(qtd<m+1 and j<n) break;
    }

    for(ll &i:v) if(i==-1LL) i = 13;

    for(ll i:v) cout << i << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
