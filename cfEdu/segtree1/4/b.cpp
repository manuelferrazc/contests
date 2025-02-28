#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll mod;

struct M {
    ll m[2][2];

    M(bool i = false) {
        m[0][0] = m[0][1] = m[1][0] = m[1][1] = 0;
        if(i) m[0][0] = m[1][1] = 1;
    }

    void operator=(M o) {
        m[0][0] = o.m[0][0];
        m[0][1] = o.m[0][1];
        m[1][0] = o.m[1][0];
        m[1][1] = o.m[1][1];
    }

    M operator*(M &o) {
        M r;
        r.m[0][0] = (m[0][0]*o.m[0][0] + m[0][1]*o.m[1][0])%mod;
        r.m[0][1] = (m[0][0]*o.m[0][1] + m[0][1]*o.m[1][1])%mod;
        r.m[1][0] = (m[1][0]*o.m[0][0] + m[1][1]*o.m[1][0])%mod;
        r.m[1][1] = (m[1][0]*o.m[0][1] + m[1][1]*o.m[1][1])%mod;
        return r;
    }

    void read() {
        cin >> m[0][0] >> m[0][1] >> m[1][0] >> m[1][1];
        ll *x = &m[0][0];
        for(unsigned i=0;i<4;i++) *(x+i) = (*(x+i))%mod;
    }

    void print() {
        cout << m[0][0] << ' ' << m[0][1] << '\n' << m[1][0] << ' ' << m[1][1] << "\n\n";
    }
};

vector<M> v, st;

void build(ll pos, ll l, ll r) {
    if(l==r) {
        st[pos] = v[l];
        return;
    }

    ll m = (l+r)>>1LL, ls = 2*pos+1;
    build(ls,l,m);
    build(ls+1,m+1,r);
    st[pos] = st[ls]*st[ls+1];
}

M get(ll pos, ll l, ll r, ll lq, ll rq) {
    if(r<lq or rq<l) return M(true);
    if(lq<=l and r<=rq) return st[pos];

    ll m = (l+r)>>1;
    auto m1 = get(2*pos+1,l,m,lq,rq), m2 = get(2*pos+2,m+1,r,lq,rq);
    return m1*m2;
}

int main() { _
    ll n,m,l,r;
    cin >> mod >> n >> m;

    v.assign(n,M());
    st.assign(n<<2,M());
    for(ll i=0;i<n;i++) v[i].read();
    build(0,0,n-1);

    while(m--) {
        cin >> l >> r;
        l--;
        r--;
        get(0,0,n-1,l,r).print();
    }

    return 0;
}
