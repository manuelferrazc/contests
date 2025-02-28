#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> v;
vector<pair<ll,ll>> st;

pair<ll,ll> build(ll pos, ll l, ll r) {
    if(l==r) return st[pos] = make_pair(v[l],1LL);

    ll m = (l+r)>>1;
    auto a = build(2*pos+1,l,m), b = build(2*pos+2,m+1,r);
    if(a.ff==b.ff) st[pos] = make_pair(a.ff,a.ss+b.ss);
    else st[pos] = min(a,b);

    return st[pos];
}

pair<ll,ll> set(ll pos, ll l, ll r, ll i, ll e) {
    if(i<l or r<i) return st[pos];
    if(l==r) return st[pos] = make_pair(e,1LL);

    ll m = (l+r)>>1;
    auto a = ::set(2*pos+1,l,m,i,e), b = ::set(2*pos+2,m+1,r,i,e);
    if(a.ff==b.ff) st[pos] = make_pair(a.ff,a.ss+b.ss);
    else st[pos] = min(a,b);

    return st[pos];
}

auto get(ll pos, ll l, ll r, ll a, ll b) {
    if(r<a or b<l) return make_pair(LLONG_MAX,1LL);
    if(a<=l and r<=b) return st[pos];

    ll m = (l+r)>>1;
    auto x = get(2*pos+1,l,m,a,b), y = get(2*pos+2,m+1,r,a,b);
    if(x.ff==y.ff) return make_pair(x.ff,x.ss+y.ss);
    else return min(x,y);
}


int main() { _
    int n, m, op,a,b;
    cin >> n >> m;
    v.assign(n,0);
    st.resize(4*n);
    for(auto &i:v) cin >> i;
    build(0,0,n-1);

    while(m--) {
        cin >> op >> a >> b;
        if(op==1) ::set(0,0,n-1,a,b);
        else {
            pair<ll,ll> x = get(0,0,n-1,a,b-1);
            cout << x.ff << ' ' << x.ss << '\n';
        }
    }

    return 0;
}
