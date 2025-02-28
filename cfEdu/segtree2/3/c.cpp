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


    ll getMax(ll pos) {
        return st[pos]+lazy[pos];
    }

    void propag(ll pos, ll l, ll r) {
        if(l==r) {
            st[pos]+=lazy[pos];
            lazy[pos] = 0;
            return;
        }

        ll p = 2*pos+1;
        lazy[p]+=lazy[pos];
        lazy[p+1]+=lazy[pos];
        st[pos]+=lazy[pos];
        lazy[pos] = 0;
    }

    ll add(ll pos, ll l, ll r, ll lq, ll rq, ll v) {
        if(r<lq or rq<l) return getMax(pos);
        if(lq<=l and r<=rq) {
            lazy[pos]+=v;
            return getMax(pos);
        }

        propag(pos,l,r);

        ll m = (l+r)>>1;
        add(2*pos+1,l,m,lq,rq,v);
        add(2*pos+2,m+1,r,lq,rq,v);
        st[pos] = max(getMax(2*pos+1),getMax(2*pos+2));

        return st[pos];
    }

    bool get(ll pos, ll l, ll r, ll i, ll x) {
        propag(pos,l,r);
        if(i>r or getMax(pos)<x) return false;
        if(l==r) {
            cout << l << '\n';
            return true;
        }
        ll m = (l+r)>>1;
        if(getMax(2*pos+1)>=x and get(2*pos+1,l,m,i,x)) return true;;
        return get(2*pos+2,m+1,r,i,x);
        // return lazy[pos]+min(get(2*pos+1,l,m,lq,rq),get(2*pos+2,m+1,r,lq,rq));
    }

public:

    SegTree(ll _n) {
        n = _n;
        st.assign(n<<2,0);
        lazy.assign(n<<2,0);
    }

    void add(ll l, ll r, ll v) {
        add(0,0,n-1,l,r,v);
    }

    bool get(ll x, ll l) {
        return get(0,0,n-1,l,x);
    }
};

int main() {
    ll n,m,l,r,v;
    int op;
    cin >> n >> m;

    SegTree st(n);

    while(m--) {
        cin >> op >> l >> r;

        if(op&1LL) {
            cin >> v;
            st.add(l,r-1,v) ;
        } else if(not st.get(l,r)) cout << "-1\n";
    }

    return 0;
}   