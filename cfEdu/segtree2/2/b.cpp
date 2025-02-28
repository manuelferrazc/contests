#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007LL;

class SegTree {
private:
    vector<ll> st;
    vector<ll> lazy;
    ll n;

    ll build(ll pos, ll l, ll r) {
        if(l==r) return st[pos] = 1;

        ll m = (l+r)>>1;
        return st[pos] = build(2*pos+1,l,m)+build(2*pos+2,m+1,r);
    }
    
    ll getSum(ll pos) {
        return (st[pos]*lazy[pos])%mod;
    }
    
    void propag(ll pos, ll l, ll r) {
        if(l==r) {
            st[pos]=(st[pos]*lazy[pos])%mod;
            lazy[pos] = 1;
            return;
        }
        
        ll p = 2*pos+1;
        lazy[p]=(lazy[pos]*lazy[p])%mod;
        lazy[p+1]=(lazy[pos]*lazy[p+1])%mod;
        lazy[pos] = 1;
        st[pos] = (getSum(p)+getSum(p+1))%mod;
    }
    
    ll multiply(ll pos, ll l, ll r, ll lq, ll rq, ll v) {
        propag(pos,l,r);
        if(r<lq or rq<l) return st[pos];
        if(lq<=l and r<=rq) {
            lazy[pos]=(v*lazy[pos])%mod;
            return getSum(pos);
        }
        
        ll m = (l+r)>>1;
        multiply(2*pos+1,l,m,lq,rq,v);
        multiply(2*pos+2,m+1,r,lq,rq,v);
        st[pos] = getSum(2*pos+1)+getSum(2*pos+2);

        return st[pos];
    }

    ll get(ll pos, ll l, ll r, ll lq, ll rq) {
        if(r<lq or rq<l) return 0;
        if(lq<=l and r<=rq) return getSum(pos);
        ll m = (l+r)>>1;
        return (lazy[pos]*(get(2*pos+1,l,m,lq,rq)+get(2*pos+2,m+1,r,lq,rq)))%mod;
    }
    
public:

    SegTree(ll _n) {
        n = _n;
        st.assign(n<<2,0LL);
        lazy.assign(n<<2,1LL);
        build(0,0,n-1);
    }

    void multiply(ll l, ll r, ll v) {
        multiply(0,0,n-1,l,r,v);
    }
    
    ll get(ll l, ll r) {
        return get(0,0,n-1,l,r);
    }
};

int main() { 
    ll n,m,l,r,v;
    int op;
    cin >> n >> m;

    SegTree st(n);

    while(m--) {
        cin >> op >> l >> r;
        r--;

        if(op&1LL) {
            cin >> v;
            st.multiply(l,r,v) ;   
        } else cout << st.get(l,r) << '\n';
    }

    return 0;
}
