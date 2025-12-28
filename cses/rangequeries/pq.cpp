#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct SegTree {
    ll *st;
    ll *lz;
    ll *lzh;
    int n;

    ll build(int pos, int l, int r, int *v) {
        lz[pos] = lzh[pos] = 0;
        if(l==r) return st[pos] = v[l];

        int m = (l+r)>>1, ls = 2*pos+1;
        return st[pos] = build(ls,l,m,v)+build(ls+1,m+1,r,v);
    }

    SegTree(int _n, int *v) {
        n = _n;
        st = new ll[4*n];
        lz = new ll[4*n];
        lzh = new ll[4*n];

        build(0,0,n-1,v);
    }

    ~SegTree() {
        delete[] st;
        delete[] lz;
        delete[] lzh;
    }

    void propag(int pos, int l, int r) {
        ll sz = r-l+1;
        st[pos] += sz*lz[pos] + lzh[pos]*(sz+1)*sz/2;

        if(sz>1) {
            int ls = 2*pos+1, m = (l+r)>>1;
            lzh[ls] += lzh[pos];
            lzh[ls+1] += lzh[pos];

            lz[ls] += lz[pos];
            lz[ls+1] += (m-l+1)*lzh[pos]+lz[pos];
        }

        lz[pos] = lzh[pos] = 0;
    }

    ll get(int pos, int l, int r, int lq, int rq) {
        if(rq<l or r<lq) return 0;

        propag(pos,l,r);
        if(lq<=l and r<=rq) return st[pos];
        
        int m = (l+r)>>1, ls = 2*pos+1;
        return get(ls,l,m,lq,rq)+get(ls+1,m+1,r,lq,rq);
    }

    ll get(int l, int r) {
        return get(0,0,n-1,l,r);
    }

    ll add(int pos, int l, int r, int lq, int rq, ll qtd=0) {
        propag(pos,l,r);
        if(rq<l or r<lq) return st[pos];
        if(lq<=l and r<=rq) {
            lzh[pos]++;
            lz[pos]+=qtd;
            propag(pos,l,r);
            return st[pos];
        }

        int m = (l+r)>>1, ls = 2*pos+1;

        ll nqtd=0;

        if(lq<=m and m<=rq) nqtd = m-max(lq,l)+1;
        return st[pos] = add(ls,l,m,lq,rq,qtd)+add(ls+1,m+1,r,lq,rq,qtd+nqtd);
    }

    void add(int l, int r) {
        add(0,0,n-1,l,r);
    }
};

int main() { _
    int n,q;
    cin >> n >> q;

    int v[n];
    for(int i=0;i<n;i++) cin >> i[v];

    SegTree st(n,v);

    int op,a,b;

    while(q--) {
        cin >> op >> a >> b;
        a--;
        b--;

        if(op==1) st.add(a,b);
        else cout << st.get(a,b) << '\n';
    }
    
    return 0;
}
