#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> st,v;

ll build(ll pos, ll l, ll r) {
    if(l==r) return st[pos] = v[l];

    ll m = (l+r)>>1;
    return st[pos] = min(build(2*pos+1,l,m),build(2*pos+2,m+1,r));
}

ll set(ll pos, ll l, ll r, ll i, ll e) {
    if(i<l or r<i) return st[pos];
    if(l==r) return st[pos] = e;

    ll m = (l+r)>>1;
    return st[pos] = min(::set(2*pos+1,l,m,i,e),::set(2*pos+2,m+1,r,i,e));
}

ll get(ll pos, ll l, ll r, ll a, ll b) {
    if(r<a or b<l) return LLONG_MAX;
    if(a<=l and r<=b) return st[pos];

    ll m = (l+r)>>1;
    return min(get(2*pos+1,l,m,a,b),get(2*pos+2,m+1,r,a,b));
}


int main() { _
    int n, m, op,a,b;
    cin >> n >> m;
    v.assign(n,0);
    st.assign(4*n,0);
    for(auto &i:v) cin >> i;
    build(0,0,n-1);

    while(m--) {
        cin >> op >> a >> b;
        if(op==1) ::set(0,0,n-1,a,b);
        else cout << get(0,0,n-1,a,b-1) << '\n';
    }

    return 0;
}
