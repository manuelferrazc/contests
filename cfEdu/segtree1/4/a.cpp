#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;

ll build(vector<ll> &v, vector<ll> &st, ll pos, ll l, ll r) {
    if(l==r) return st[pos] = v[l];

    ll m = (l+r)>>1;
    return st[pos] = build(v,st,2*pos+1,l,m) + build(v,st,2*pos+2,m+1,r);
}

ll set(vector<ll> &st, ll pos, ll l, ll r, ll i, ll v) {
    if(i<l or r<i) return st[pos];
    if(l==r) return st[pos] = v;

    ll m = (l+r)>>1;
    return st[pos] = ::set(st,2*pos+1,l,m,i,v)+::set(st,2*pos+2,m+1,r,i,v);
}

ll get(vector<ll> &st, ll pos, ll l, ll r, ll lq, ll rq) {
    if(r<lq or rq<l) return 0U;
    if(lq<=l and r<=rq) return st[pos];

    ll m = (l+r)>>1;
    return get(st,2*pos+1,l,m,lq,rq)+get(st,2*pos+2,m+1,r,lq,rq);
}

int main() { _
    ll n,m;
    cin >> n;

    vector<ll> pa(n+1,0U), im(n+1,0U);
    for(ll i=1;i<=n;i++) {
        cin >> m;
        if(i&1) im[i] = m;
        else pa[i] = m;
    }

    vector<ll> sp((n+1)<<2), si((n+1)<<2);
    build(pa,sp,0,1,n);
    build(im,si,0,1,n);

    cin >> m;
    ll op,a,b;

    while(m--) {
        cin >> op >> a >> b;

        if(op==0) {
            if(a&1) ::set(si,0,1,n,a,b);
            else ::set(sp,0,1,n,a,b);
        } else {
            op = get(si,0,1,n,a,b)-get(sp,0,1,n,a,b);
            cout << (a&1? op : -op) << '\n';
        }
    }
    return 0;
}
