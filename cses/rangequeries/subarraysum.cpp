#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct seg {
    ll pref,suf,mx,sum;

    seg(ll p=0, ll s=0, ll max=0, ll su=0): pref(p), suf(s), mx(max), sum(su) {}
};

seg *st;
int *v;

void build(int pos, int l, int r) {
    if(l==r) {
        st[pos].pref = st[pos].suf = st[pos].mx = st[pos].sum = v[l];
        return;
    }

    int ls = 2*pos+1, m = (l+r)>>1;
    build(ls,l,m);
    build(ls+1,m+1,r);

    st[pos].pref = max(st[ls].pref,st[ls].sum+st[ls+1].pref);
    st[pos].suf = max(st[ls+1].suf,st[ls+1].sum+st[ls].suf);
    st[pos].sum = st[ls].sum+st[ls+1].sum;
    st[pos].mx = max({st[ls].mx,st[ls+1].mx,st[ls].suf+st[ls+1].pref});
}

void change(int pos, int l, int r, int i, int x) {
    if(i<l or r<i) return;
    if(l==r) {
        st[pos].pref = st[pos].suf = st[pos].mx = st[pos].sum = x;
        return;
    }
    
    int ls = 2*pos+1, m = (l+r)>>1;
    change(ls,l,m,i,x);
    change(ls+1,m+1,r,i,x);

    st[pos].pref = max(st[ls].pref,st[ls].sum+st[ls+1].pref);
    st[pos].suf = max(st[ls+1].suf,st[ls+1].sum+st[ls].suf);
    st[pos].sum = st[ls].sum+st[ls+1].sum;
    st[pos].mx = max({st[ls].mx,st[ls+1].mx,st[ls].suf+st[ls+1].pref});
}

seg get(int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return seg();
    if(lq<=l and r<=rq) return st[pos];

    int ls = 2*pos+1, m = (l+r)>>1;
    seg a = get(ls,l,m,lq,rq);
    seg b = get(ls+1,m+1,r,lq,rq);

    return seg(
        max(a.pref,a.sum+b.pref),
        max(b.suf,b.sum+a.suf),
        max({a.mx,b.mx,a.suf+b.pref}),
        a.sum+b.sum
    );
}

int main() { _
    int n,q;
    cin >> n >> q;

    st = new seg[4*n];
    v = new int[n];

    for(int i=0;i<n;i++) cin >> v[i];

    build(0,0,n-1);

    while(q--) {
        int a,b;
        cin >> a >> b;
        a--;

        change(0,0,n-1,a,b);

        cout << max(st[0].mx,0LL) << '\n';
    }

    delete[] st;
    delete[] v;

    return 0;
}
