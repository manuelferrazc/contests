#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int *v, *st1, *st2, n;

void build(int pos, int l, int r) {
    if(l==r) {
        st1[pos] = v[l]+l;
        st2[pos] = v[l]+(n-l-1);
        return;
    }

    int ls = 2*pos+1, m = (l+r)/2;
    build(ls,l,m);
    build(ls+1,m+1,r);

    st1[pos] = min(st1[ls],st1[ls+1]);
    st2[pos] = min(st2[ls],st2[ls+1]);
}

void change(int pos, int l, int r, int i, int x) {
    if(i<l or r<i) return;
    if(l==r) {
        st1[pos] = x+l;
        st2[pos] = x+(n-l-1);
        return;
    }

    int ls = 2*pos+1, m = (l+r)/2;
    change(ls,l,m,i,x);
    change(ls+1,m+1,r,i,x);

    st1[pos] = min(st1[ls],st1[ls+1]);
    st2[pos] = min(st2[ls],st2[ls+1]);
}

int get1(int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return INT_MAX;
    if(lq<=l and r<=rq) return st1[pos];
    int ls = 2*pos+1, m = (l+r)/2;

    return min(get1(ls,l,m,lq,rq),get1(ls+1,m+1,r,lq,rq));
}

int get2(int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return INT_MAX;
    if(lq<=l and r<=rq) return st2[pos];
    int ls = 2*pos+1, m = (l+r)/2;

    return min(get2(ls,l,m,lq,rq),get2(ls+1,m+1,r,lq,rq));
}

int main() { _
    int q,op,a,b;
    cin >> n >> q;

    v = new int[n];
    st1 = new int[4*n];
    st2 = new int[4*n];
    
    for(int i=0;i<n;i++) cin >> v[i];

    build(0,0,n-1);

    while(q--) {
        cin >> op >> a;

        if(op==1) {
            cin >> b;
            change(0,0,n-1,a-1,b);
        } else cout << min(get1(0,0,n-1,a-1,n-1)-a+1,get2(0,0,n-1,0,a-1)-(n-a)) << '\n';
    }

    delete[] v;
    delete[] st1;
    delete[] st2;

    return 0;
}
