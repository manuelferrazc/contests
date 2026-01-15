#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct SegTree {
    ll *sum;
    ll *lz_add;
    ll *lz_st;
    int n;

    ll build(int pos, int l, int r, int *v) {
        lz_add[pos] = lz_st[pos] = 0;
        if(l==r) return sum[pos] = v[l];

        int m = (l+r)>>1, ls = 2*pos+1;
        return sum[pos] = build(ls,l,m,v)+build(ls+1,m+1,r,v);
    }

    SegTree(int _n, int *v) {
        n = _n;
        sum = new ll[4*n];
        lz_add = new ll[4*n];
        lz_st = new ll[4*n];

        build(0,0,n-1,v);
    }

    ~SegTree() {
        delete[] sum;
        delete[] lz_add;
        delete[] lz_st;
    }

    void propag(int pos, int l, int r) {
        if(l==r) {
            if(lz_st[pos]) sum[pos] = lz_st[pos];
            sum[pos]+=lz_add[pos];
            lz_add[pos] = lz_st[pos] = 0;
            return;
        }

        int ls = 2*pos+1;
        
        if(lz_add[pos]==0 and lz_st[pos]==0) return;
        else if(lz_add[pos]==0) { // só o lz_st tá ligado
            lz_st[ls] = lz_st[ls+1] = lz_st[pos];
            lz_add[ls] = lz_add[ls+1] = 0;
            sum[pos] = (r-l+1)*lz_st[pos];
        } else if(lz_st[pos]==0) { // só o lz_add tá ligado
            lz_add[ls]+=lz_add[pos];
            lz_add[ls+1]+=lz_add[pos];
            sum[pos] += lz_add[pos]*(r-l+1);
        } else { // tenho q setar E somar
            lz_add[ls] = lz_add[ls+1] = lz_add[pos];
            lz_st[ls] = lz_st[ls+1] = lz_st[pos];
            sum[pos] = (lz_st[pos]+lz_add[pos])*(r-l+1);
        }
            
        lz_add[pos] = lz_st[pos] = 0;
    }

    ll get(int pos, int l, int r, int lq, int rq) {
        propag(pos,l,r);
        if(rq<l or r<lq) return 0;
        if(lq<=l and r<=rq) return sum[pos];

        int m = (l+r)>>1, ls = 2*pos+1;
        return get(ls,l,m,lq,rq)+get(ls+1,m+1,r,lq,rq);
    }
    
    ll add(int pos, int l, int r, int lq, int rq, int val) {
        propag(pos,l,r);
        if(rq<l or r<lq) return sum[pos];
        if(lq<=l and r<=rq) {
            lz_add[pos]+=val;
            propag(pos,l,r);
            return sum[pos];
        }

        int m = (l+r)>>1, ls = 2*pos+1;
        return sum[pos] = add(ls,l,m,lq,rq,val)+add(ls+1,m+1,r,lq,rq,val);
    }
    
    ll st(int pos, int l, int r, int lq, int rq, int val) {
        propag(pos,l,r);
        if(rq<l or r<lq) return sum[pos];
        if(lq<=l and r<=rq) {
            lz_st[pos] = val;
            propag(pos,l,r);
            return sum[pos];
        }

        int m = (l+r)>>1, ls = 2*pos+1;
        return sum[pos] = st(ls,l,m,lq,rq,val)+st(ls+1,m+1,r,lq,rq,val);
    
    }

    ll get(int l, int r) {
        return get(0,0,n-1,l,r);
    }
    
    void add(int l, int r, int val) {
        add(0,0,n-1,l,r,val);
    }

    void st(int l, int r, int val) {
        st(0,0,n-1,l,r,val);
    }
};

int main() { _
    int n,q;
    cin >> n >> q;

    int v[n];
    for(int i=0;i<n;i++) cin >> i[v];

    SegTree st(n,v);
    int a,b,c,op;

    while(q--) {
        cin >> op >> a >> b;
        a--;
        b--;

        if(op==1) {
            cin >> c;
            st.add(a,b,c);
        } else if(op==2) {
            cin >> c;
            st.st(a,b,c);
        } else cout << st.get(a,b) << '\n';
    }
    
    return 0;
}
