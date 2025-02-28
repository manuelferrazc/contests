#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll qtd;
ll menor;

ll foo(ll l, ll r, ll k) {
    ll s = r-l+1, m=(l+r)/2LL;
    if(s<k) return 0;
    if(s&1LL) {
        qtd++;
        menor=min(menor,m);
        return m + foo(m+1,r,k) + foo(l,m-1,k);
    } else {
        return foo(m+1,r,k) + foo(l,m,k);
    }
}

void solve() {
    ll n,k,x;
    cin >> x >> n >> k;
    qtd=0;
    menor=INT_MAX;
    cout << foo(x,n,k) << ' ' << qtd << ' ' << menor << '\n';    
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
