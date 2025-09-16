#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void build(int *v, ll *sp, int pos, int l, int r) {
    if(l==r) {
        sp[pos] = v[l];
        return;
    }
    
    sp[pos] = 0;
    int m = (l+r)/2, ls = 2*pos+1;
    build(v,sp,ls,l,m);
    build(v,sp,ls+1,m+1,r);
}

ll get(ll *sp, int pos, int l, int r, int i) {
    if(i<l or r<i) return 0;
    if(l==r) return sp[pos];
    
    int m = (l+r)/2, ls = 2*pos+1;
    return get(sp,ls,l,m,i)+get(sp,ls+1,m+1,r,i)+sp[pos];
}

void change(ll *sp, int pos, int l, int r, int lq, int rq, int x) {
    if(rq<l or r<lq) return;
    if(lq<=l and r<=rq) {
        sp[pos] += x;
        return;
    }

    int m = (l+r)/2, ls = 2*pos+1;
    change(sp,ls,l,m,lq,rq,x);
    change(sp,ls+1,m+1,r,lq,rq,x);
}

int main() { _
    int n,q,op,a,b,u;
    cin >> n >> q;

    int v[n];
    ll sp[4*n];
    for(int i=0;i<n;i++) cin >> v[i];

    build(v,sp,0,0,n-1);

    while(q--) {
        cin >> op >> a;
        a--;

        if(op==1) {
            cin >> b >> u;
            b--;

            change(sp,0,0,n-1,a,b,u);
        }
        else cout << get(sp,0,0,n-1,a) << '\n';
    }
    
    return 0;
}
