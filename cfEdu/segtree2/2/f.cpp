#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


class SegTree {
private:
    vector<ll> st;
    vector<ll> lazy;
    ll n;

    
    ll getSum(ll pos, ll l, ll r) {
        return (lazy[pos]==-1 ? st[pos] : lazy[pos]*(r-l+1));
    }
    
    void propag(ll pos, ll l, ll r) {
        if(lazy[pos]==-1) return;

        if(l==r) {
            st[pos] = lazy[pos];
            lazy[pos] = -1;
            return;
        }
        
        ll p = 2*pos+1,m=(l+r)>>1;
        lazy[p]=lazy[p+1]=lazy[pos];
        lazy[pos] = -1;
        st[pos] = getSum(p,l,m)+getSum(p+1,m+1,r);
    }
    
    ll assign(ll pos, ll l, ll r, ll lq, ll rq, ll v) {
        propag(pos,l,r);
        if(r<lq or rq<l) return st[pos];
        if(lq<=l and r<=rq) {
            lazy[pos] = v;
            return getSum(pos,l,r);
        }
        
        ll m = (l+r)>>1, p=2*pos+1;
        assign(p,l,m,lq,rq,v);
        assign(p+1,m+1,r,lq,rq,v);
        st[pos] = getSum(p,l,m)+getSum(p+1,m+1,r);

        return st[pos];
    }

    ll getSum(ll pos, ll l, ll r, ll lq, ll rq) {
        propag(pos,l,r);
        if(r<lq or rq<l) return 0LL;
        if(lq<=l and r<=rq) return st[pos];
        ll m = (l+r)>>1,p=2*pos+1;
        return getSum(p,l,m,lq,rq)+getSum(p+1,m+1,r,lq,rq);
    }
    
public:

    SegTree(ll _n) {
        n = _n;
        st.assign(n<<2,0);
        lazy.assign(n<<2,-1);
    }

    void assign(ll l, ll r, ll v) {
        assign(0,0,n-1,l,r,v);
    }
    
    ll getSum(ll l, ll r) {
        return getSum(0,0,n-1,l,r);
    }
};

int main() { 
    ll n,m,l,r,v;
    ll op;
    cin >> n >> m;

    SegTree st(n);

    while(m--) {
        cin >> op >> l >> r;
        r--;

        if(op==1) {
            cin >> v;
            st.assign(l,r,v) ;   
        } else cout << st.getSum(l,r) << '\n';
    }

    return 0;
}
