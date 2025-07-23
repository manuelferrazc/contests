#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;

ll fexp(ll n, ll e) {
    if(e==0) return 1;
    if(e==1) return n;
    
    ll r = fexp(n,e>>1);
    r = r*r%mod;
    if(e&1) r = r*n%mod;
    
    return r;
}

struct seg {
    ll l,r,p,q;
    
    seg() {}
    seg(ll _l,ll _r,ll _p, ll _q) {
        l = _l;
        r = _r;
        p = _p;
        q = _q;
    }
    
    bool const operator<(const seg& o) {
        if(l<o.l) return true;
        if(l==o.l and r<o.r) return true;
        return false;
    }
};

ll gcd(pair<ll,ll> &p) {
    return gcd(p.ff,p.ss);
}

pair<ll,ll> prod(pair<ll,ll> a, pair<ll,ll> &b) {
    return make_pair(a.ff*b.ff%mod,a.ss*b.ss%mod);
}

pair<ll,ll> sum(pair<ll,ll> &a, pair<ll,ll> &b) {
    return make_pair((a.ff*b.ss+a.ss*b.ff)%mod,a.ss*b.ss%mod);
}

vector<seg> v;
vector<pair<ll,ll>> dp(200'001,{-1,-1}), st(800'000);
ll n,m;

pair<ll,ll> build(ll pos, ll l, ll r) {
    if(l==r) return st[pos] = make_pair(v[l].q-v[l].p,v[l].q);

    ll m = (l+r)>>1,ls = 2*pos+1;
    auto p1 = build(ls,l,m),p2 = build(ls+1,m+1,r);
    
    return st[pos] = prod(p1,p2);
}

pair<ll,ll> get(ll pos, ll l, ll r, ll lq, ll rq) {
    if(r<lq or rq<l) return pair<ll,ll>(1,1);
    if(lq<=l and r<=rq) return st[pos];

    ll m = (l+r)>>1,ls = 2*pos+1;
    auto p1 = get(ls,l,m,lq,rq),p2 = get(ls+1,m+1,r,lq,rq);

    return prod(p1,p2);
}

pair<ll,ll> ddp(ll i) {
    if(i>m) return make_pair(1,1);
    if(dp[i].ff!=-1) return dp[i];
    auto it = lower_bound(v.begin(),v.end(),seg(i,-1,0,0));

    if(it==v.end() or it->l>i) return dp[i] = make_pair(0,1);
    dp[i].ff = 0;
    dp[i].ss = 1;
    ll pos = it-v.begin();
    ll init = pos;
    while(pos<n and v[pos].l==v[init].l) {
        auto p = ddp(v[pos].r+1);
        ll mx = lower_bound(v.begin(),v.end(),seg(v[pos].r+1,0,0,0)) - v.begin()-1;

        pair<ll,ll> pnot(1,1);

        if(pos!=init) pnot = get(0,0,n-1,init,pos-1);
        if(pos!=mx) pnot = prod(get(0,0,n-1,pos+1,mx),pnot);

        // prob de usar esse e nenhum dos outros
        pair<ll,ll> pok = prod(make_pair(v[pos].p,v[pos].q),pnot);

        // combina com a dp do resto já calculado
        pok = prod(pok,p);

        // combina com a do pra posicao atual
        dp[i] = sum(dp[i],pok);
        pos++;
    }
    return dp[i];
}


void solve() {
    cin >> n >> m;

    for(ll i=0;i<n;i++) {
        ll l,r,p,q;
        cin >> l >> r >> p >> q;
        v.push_back(seg(l,r,p,q));
    }

    sort(v.begin(),v.end());
    build(0,0,n-1);

    auto p = ddp(1);
    cout << (p.ff*fexp(p.ss,mod-2))%mod << '\n';
}

int main() {
    solve();
    return 0;
}
