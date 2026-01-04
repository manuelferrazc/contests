#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int st[4000][4000];
struct SegTree {
    int n;

    string *v;

    int recalc(int pos1, int pos, int l, int r, int i=-1) {
        if(l==r) return st[pos1][pos] = st[2*pos1+1][pos]+st[2*pos1+2][pos];

        int m = (l+r)>>1, ls = 2*pos+1;
        if(i==-1 or i<=m) recalc(pos1,ls,l,m,i);
        if(i==-1 or i>m) recalc(pos1,ls+1,m+1,r,i);

        return st[pos1][pos] = st[pos1][ls]+st[pos1][ls+1];
    }

    int build2(int pos1, int row, int pos, int l, int r) {
        if(l==r) return st[pos1][pos] = (v[row][l]=='*');

        int m = (l+r)>>1, ls = 2*pos+1;
        return st[pos1][pos] = build2(pos1,row,ls,l,m)+build2(pos1,row,ls+1,m+1,r);
    }

    void build1(int pos, int l, int r) {
        if(l==r) build2(pos,l,0,0,n-1);
        else {
            int m = (l+r)>>1, ls = 2*pos+1;

            build1(ls,l,m);
            build1(ls+1,m+1,r);
            recalc(pos,0,0,n-1);
        }
    }

    SegTree(string *_v, int _n) {
        n = _n;
        v = _v;


        build1(0,0,n-1);
    }

    ~SegTree() {
    }

    int change2(int pos1, int pos, int l, int r, int j) {
        if(l==r) return st[pos1][pos]^=1;
        
        int m = (l+r)>>1, ls = 2*pos+1;
        if(j<=m) change2(pos1,ls,l,m,j);
        else change2(pos1,ls+1,m+1,r,j);

        return st[pos1][pos] = st[pos1][ls]+st[pos1][ls+1];
    }

    void change(int pos, int l, int r, int i, int j) {
        if(l==r) {
            change2(pos,0,0,n-1,j);
            return;
        }

        int m = (l+r)>>1, ls = 2*pos+1;
        if(i<=m) change(ls,l,m,i,j);
        else change(ls+1,m+1,r,i,j);

        recalc(pos,0,0,n-1,j);
    }

    void change(int i, int j) {
        change(0,0,n-1,i,j);
    }

    int get2(int pos1, int pos, int l, int r, int lq, int rq) {
        if(rq<l or r<lq) return 0;
        if(lq<=l and r<=rq) return st[pos1][pos];

        int m = (l+r)>>1, ls = 2*pos+1;
        return get2(pos1,ls,l,m,lq,rq)+get2(pos1,ls+1,m+1,r,lq,rq);
    }

    int get(int pos, int l, int r, int l1, int r1, int l2, int r2) {
        if(r1<l or r<l1) return 0;
        if(l1<=l and r<=r1) return get2(pos,0,0,n-1,l2,r2);

        int m = (l+r)>>1, ls = 2*pos+1;
        return get(ls,l,m,l1,r1,l2,r2)+get(ls+1,m+1,r,l1,r1,l2,r2);
    }

    int get(int l1, int r1, int l2, int r2) {
        return get(0,0,n-1,l1,r1,l2,r2);
    }
};

int main() { _
    int n,q;
    cin >> n >> q;
    
    string v[n];
    for(int i=0;i<n;i++) cin >> i[v];

    SegTree st(v,n);

    int op,a,b,c,d;

    vector<int> ans;
    for(int i=0;i<q;i++) {
        cin >> op >> a >> b;

        a--;
        b--;

        if(op==1) st.change(a,b);
        else {
            cin >> c >> d;
            c--;
            d--;

            ans.push_back(st.get(a,c,b,d));
        }
    }

    for(int i:ans) cout << i << '\n';
    
    return 0;
}
