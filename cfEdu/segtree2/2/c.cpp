#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


class SegTree {
private:
    vector<int> st;
    vector<int> lazy;
    int n;

    
    int getAnd(int pos) {
        return st[pos]|lazy[pos];
    }
    
    void propag(int pos, int l, int r) {
        if(l==r) {
            st[pos]|=lazy[pos];
            lazy[pos] = 0;
            return;
        }
        
        int p = 2*pos+1;
        lazy[p]|=lazy[pos];
        lazy[p+1]|=lazy[pos];
        lazy[pos] = 0;
        st[pos] = getAnd(p)&getAnd(p+1);
    }
    
    int applyOr(int pos, int l, int r, int lq, int rq, int v) {
        propag(pos,l,r);
        if(r<lq or rq<l) return st[pos];
        if(lq<=l and r<=rq) {
            lazy[pos]|=v;
            return getAnd(pos);
        }
        
        int m = (l+r)>>1, p=2*pos+1;
        applyOr(p,l,m,lq,rq,v);
        applyOr(p+1,m+1,r,lq,rq,v);
        st[pos] = getAnd(p)&getAnd(p+1);

        return st[pos];
    }

    int getAnd(int pos, int l, int r, int lq, int rq) {
        if(r<lq or rq<l) return -1;
        if(lq<=l and r<=rq) return getAnd(pos);
        int m = (l+r)>>1,p=2*pos+1;
        return lazy[pos]|(getAnd(p,l,m,lq,rq)&getAnd(p+1,m+1,r,lq,rq));
    }
    
public:

    SegTree(int _n) {
        n = _n;
        st.assign(n<<2,0);
        lazy.assign(n<<2,0);
    }

    void applyOr(int l, int r, int v) {
        applyOr(0,0,n-1,l,r,v);
    }
    
    int getAnd(int l, int r) {
        return getAnd(0,0,n-1,l,r);
    }
};

int main() { 
    int n,m,l,r,v;
    int op;
    cin >> n >> m;

    SegTree st(n);

    while(m--) {
        cin >> op >> l >> r;
        r--;

        if(op&1) {
            cin >> v;
            st.applyOr(l,r,v) ;   
        } else cout << st.getAnd(l,r) << '\n';
    }

    return 0;
}
