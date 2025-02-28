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

    
    int getmin(int pos) {
        return (lazy[pos]!=-1 ? lazy[pos] : st[pos]);
    }
    
    void propag(int pos, int l, int r) {
        if(lazy[pos]==-1) return;

        if(l==r) {
            st[pos] = lazy[pos];
            lazy[pos] = -1;
            return;
        }
        
        int p = 2*pos+1;
        lazy[p]=lazy[pos];
        lazy[p+1]=lazy[pos];
        lazy[pos] = -1;
        st[pos] = min(getmin(p),getmin(p+1));
    }
    
    int assign(int pos, int l, int r, int lq, int rq, int v) {
        propag(pos,l,r);
        if(r<lq or rq<l) return st[pos];
        if(lq<=l and r<=rq) return lazy[pos] = v;
        
        int m = (l+r)>>1, p=2*pos+1;
        assign(p,l,m,lq,rq,v);
        assign(p+1,m+1,r,lq,rq,v);
        st[pos] = min(getmin(p),getmin(p+1));

        return getmin(pos);
    }

    int getmin(int pos, int l, int r, int lq, int rq) {
        propag(pos,l,r);
        if(r<lq or rq<l) return INT_MAX;
        if(lq<=l and r<=rq) return getmin(pos);
        int m = (l+r)>>1,p=2*pos+1;
        return min(getmin(p,l,m,lq,rq),getmin(p+1,m+1,r,lq,rq));
    }
    
public:

    SegTree(int _n) {
        n = _n;
        st.assign(n<<2,0);
        lazy.assign(n<<2,-1);
    }

    void assign(int l, int r, int v) {
        assign(0,0,n-1,l,r,v);
    }
    
    int getmin(int l, int r) {
        return getmin(0,0,n-1,l,r);
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

        if(op==1) {
            cin >> v;
            st.assign(l,r,v) ;   
        } else cout << st.getmin(l,r) << '\n';
    }

    return 0;
}
