#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll minf = -1e15;

struct cell {
    ll pref = 0;
    ll suf = 0;
    ll sum = 0;
    ll maxseg = 0;
    cell(ll _pref=0LL, ll _suf=0LL, ll _sum=0LL, ll _maxseg=0LL) : pref(_pref), suf(_suf), sum(_sum), maxseg(_maxseg) {}
};

vector<ll> v;
vector<cell> seg;

void build(ll pos, ll l, ll r) {
    if(l==r) {
        seg[pos] = cell(v[l],v[l],v[l],v[l]);
        return;
    }

    ll m = (l+r)>>1, lf = 2*pos+1, rf = 2*pos+2;
    build(lf,l,m);
    build(rf,m+1,r);
    seg[pos] = cell(
        max(seg[lf].pref,seg[lf].sum+seg[rf].pref),
        max(seg[rf].suf,seg[rf].sum+seg[lf].suf),
        seg[lf].sum+seg[rf].sum,
        max({seg[lf].maxseg,seg[rf].maxseg,seg[lf].suf+seg[rf].pref})
    );
}

void set(ll pos, ll l, ll r, ll i, ll x) {
    if(i<l or r<i) return;
    if(l==r) {
        seg[pos] = cell(x,x,x,x);
        return;
    }

    ll m = (l+r)>>1, lf = 2*pos+1, rf = 2*pos+2;
    ::set(lf,l,m,i,x);
    ::set(rf,m+1,r,i,x);
    seg[pos] = cell(
        max(seg[lf].pref,seg[lf].sum+seg[rf].pref),
        max(seg[rf].suf,seg[rf].sum+seg[lf].suf),
        seg[lf].sum+seg[rf].sum,
        max({seg[lf].maxseg,seg[rf].maxseg,seg[lf].suf+seg[rf].pref})
    );
}

cell get(ll pos, ll l, ll r, ll lq, ll rq) {
    if(rq<l or r<lq) return cell(minf,minf,minf,minf);
    if(lq<=l and r<=rq) return seg[pos];

    ll m = (l+r)>>1, lf = 2*pos+1, rf = 2*pos+2;
    auto a = get(lf,l,m,lq,rq), b = get(rf,m+1,r,lq,rq);
    return cell(
        max(a.pref,a.sum+b.pref),
        max(b.suf,b.sum+a.suf),
        a.sum+b.sum,
        max({a.maxseg,b.maxseg,a.suf+b.pref})
    );
}

int main() { _
    ll n,q,i,x;
    cin >> n >> q;
    v.assign(n,0LL);
    seg.assign(4*n,cell());

    for(auto &i:v) cin >> i;
    build(0,0,n-1);
    cout << max(0LL,get(0,0,n-1,0,n-1).maxseg) << '\n';

    while(q--) {
        cin >> i >> x;
        ::set(0,0,n-1,i,x);
        cout << max(0LL,get(0,0,n-1,0,n-1).maxseg) << '\n';
    }
    
    return 0;
}
