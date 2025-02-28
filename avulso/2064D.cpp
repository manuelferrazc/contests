#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> v,stx,stm;

ll build1(ll pos, ll l, ll r) {
    if(l==r) {
        stx[pos] = v[l];
        return stx[pos];
    }

    ll m((l+r)>>1);
    return stx[pos] = build1(2*pos+1,l,m)^build1(2*pos+2,m+1,r);
}

ll build2(ll pos, ll l, ll r) {
    if(l==r) {
        for(int i=0;i<30;i++) if((v[l]>>i)&1) stm[pos] = i;
        return stm[pos];
    }

    ll m((l+r)>>1);
    return stm[pos] = max(build2(2*pos+1,l,m),build2(2*pos+2,m+1,r));
}

ll get1(ll pos, ll l, ll r, ll lq, ll rq) {
    if(r<lq or rq<l) return 0LL;
    if(lq<=l and r<=rq) return stx[pos];

    ll m((l+r)>>1);
    return get1(2*pos+1,l,m,lq,rq)^get1(2*pos+2,m+1,r,lq,rq);
}

ll get2(ll pos, ll l, ll r, ll lq, ll rq, ll x) {
    if(rq<l or r<lq or stm[pos]<x) return -1;
    ll m((l+r)>>1),ls = 2*pos+1;

    if(lq<=l and r<=rq) {
        if(l==r) return l;
        if(stm[ls+1]>=x) return get2(ls+1,m+1,r,lq,rq,x);
        return get2(ls,l,m,lq,rq,x);
    }

    ll a = get2(ls+1,m+1,r,lq,rq,x);
    if(a!=-1) return a;
    return get2(ls,l,m,lq,rq,x);
}

void solve() {
    ll n,q,x;
    cin >> n >> q;
    v.resize(n);
    for(auto &i:v) cin >> i;
    stx.resize(n<<2);
    stm.resize(n<<2);
    build1(0,0,n-1);
    build2(0,0,n-1);

    while(q--) {
        cin >> x;
        ll p = n;
        while(p) {
            ll m=0;
            for(ll i=0;i<30;i++) if((x>>i)&1) m=i;

            ll c = get2(0,0,n-1,0,p-1,m);
            if(c==-1) {
                p=0;
                break;
            }
            if(c!=p-1) x^=get1(0,0,n-1,c+1,p-1);
            p=c+1;
            if(x>=v[c]) {
                x^=v[c];
                p=c;
            } else break;
        }

        cout << n-p << ' ';
    }
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
