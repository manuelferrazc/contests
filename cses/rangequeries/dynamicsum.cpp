#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll build(int *v, ll *sp, int pos, int l, int r) {
    if(l==r) return sp[pos] = v[l];

    int m = (l+r)/2, ls = 2*pos+1;
    return sp[pos] = build(v,sp,ls,l,m)+build(v,sp,ls+1,m+1,r);
}

ll get(ll *sp, int pos, int l, int r, int lq, int rq) {
    if(r<lq or rq<l) return 0;
    if(lq<=l and r<=rq) return sp[pos];
    
    int m = (l+r)/2, ls = 2*pos+1;
    return get(sp,ls,l,m,lq,rq)+get(sp,ls+1,m+1,r,lq,rq);
}

ll change(ll *sp, int pos, int l, int r, int i, int x) {
    if(i<l or r<i) return sp[pos];
    if(l==r) return sp[pos] = x;

    int m = (l+r)/2, ls = 2*pos+1;
    return sp[pos] = change(sp,ls,l,m,i,x)+change(sp,ls+1,m+1,r,i,x);
}

int main() { _
    int n,q,op,a,b;
    cin >> n >> q;

    int v[n];
    ll sp[4*n];
    for(int i=0;i<n;i++) cin >> v[i];

    build(v,sp,0,0,n-1);

    while(q--) {
        cin >> op >> a >> b;
        a--;

        if(op==1) change(sp,0,0,n-1,a,b);
        else cout << get(sp,0,0,n-1,a,b-1) << '\n';
    }
    
    return 0;
}
