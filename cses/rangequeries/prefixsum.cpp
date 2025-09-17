#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;
ll *v,*sts,*stp;

void build(int pos, int l, int r) {
    if(l==r) {
        sts[pos] = stp[pos] = v[l];
        if(v[l]<0) stp[pos] = 0;
        return;
    }
    int m = (l+r)/2,ls = 2*pos+1;
    build(ls,l,m);
    build(ls+1,m+1,r);

    sts[pos] = sts[ls]+sts[ls+1];
    stp[pos] = max(stp[ls],sts[ls]+stp[ls+1]);
}

ll gets(int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return 0;
    if(lq<=l and r<=rq) return sts[pos];

    int m = (l+r)/2,ls = 2*pos+1;
    return gets(ls,l,m,lq,rq)+gets(ls+1,m+1,r,lq,rq);
}

ll get(int pos, int l, int r, int lq, int rq) {
    int m = (l+r)/2,ls = 2*pos+1;
    if(rq<l or r<lq) return 0;
    
    if(lq<=l and r<=rq) return stp[pos];

    if(rq<=m) return get(ls,l,m,lq,rq);
    if(m<lq) return get(ls+1,m+1,r,lq,rq);
    
    if(lq<=l and r<=rq) return stp[pos];

    return max(get(ls,l,m,lq,rq),gets(0,0,n-1,max(l,lq),m)+get(ls+1,m+1,r,lq,rq));
}

void change(int pos, int l, int r, int i, int x) {
    if(i<l or r<i) return;
    if(l==r) {
        stp[pos] = sts[pos] = x;
        if(x<0) stp[pos] = 0;
        return;
    }
    int m = (l+r)/2,ls = 2*pos+1;
    change(ls,l,m,i,x);
    change(ls+1,m+1,r,i,x);
    sts[pos] = sts[ls]+sts[ls+1];
    stp[pos] = max(stp[ls],sts[ls]+stp[ls+1]);
}

int main() { _
    int q,op,a,b;
    cin >> n >> q;

    v = new ll[n];
    stp = new ll[4*n];
    sts = new ll[4*n];

    for(int i=0;i<n;i++) cin >> v[i];

    build(0,0,n-1);

    while(q--) {
        cin >> op >> a >> b;

        if(op==1) change(0,0,n-1,a-1,b);
        else cout << get(0,0,n-1,a-1,b-1) << '\n';
    }

    delete[] v;
    delete[] stp;
    delete[] sts;
    
    return 0;
}
