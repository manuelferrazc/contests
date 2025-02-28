#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct Cell {
    ll pref;
    ll suf;
    ll sum;
    ll ms;

    Cell(ll _pref=0, ll _suf=0, ll _sum=0, ll _ms=0):
        pref(_pref), suf(_suf), sum(_sum), ms(_ms) {}

    Cell combine(Cell c) {
        Cell ret(
            max(pref,sum+c.pref),
            max(c.suf,c.sum+suf),
            sum+c.sum,
            max(ms,max(c.ms,suf+c.pref))
        );
        return ret;
    }
};

vector<Cell> st;
vector<ll> lazy;
ll n;

void propag(ll pos, ll l, ll r) {
    if(l==r or lazy[pos]==LLONG_MIN) return;
    lazy[2*pos+1] = lazy[2*pos+2] = lazy[pos];
    lazy[pos] = LLONG_MIN;
}

void assign(ll pos, ll l, ll r, ll lq, ll rq, ll v) {
    if(r<lq or rq<l) {
        if(lazy[pos]!=LLONG_MIN) {
            v = lazy[pos];
            if(v<=0) st[pos] = Cell();
            st[pos].sum = v*(r-l+1);
            if(v>0LL) st[pos].pref = st[pos].suf = st[pos].ms = v*(r-l+1);
        }
        return;
    }
    
    if(lq<=l and r<=rq) {
        lazy[pos] = v;
        st[pos].sum = v*(r-l+1);
        if(v>0LL) st[pos].pref = st[pos].suf = st[pos].ms = v*(r-l+1);
        else st[pos].pref = st[pos].suf = st[pos].ms = 0;
        return;
    }

    propag(pos,l,r);

    ll m = (l+r)>>1, p = 2*pos+1;
    assign(p,l,m,lq,rq,v);
    assign(p+1,m+1,r,lq,rq,v);
    st[pos] = st[p].combine(st[p+1]);
}

void assign(ll lq, ll rq, ll v) {
    assign(0,0,n-1,lq,rq,v);
}

int main() { _
    ll m,l,r,v; 
    cin >> n >> m;

    st.assign(n<<2,Cell());
    lazy.assign(n<<2,LLONG_MIN);

    while(m--) {
        cin >> l >> r >> v;
        r--;
        assign(l,r,v);
        cout << st[0].ms << '\n';
    }

    return 0;
}
