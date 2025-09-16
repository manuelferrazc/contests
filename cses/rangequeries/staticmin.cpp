#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int build(int *v, int *sp, int pos, int l, int r) {
    if(l==r) return sp[pos] = v[l];

    int m = (l+r)/2, ls = 2*pos+1;
    return sp[pos] = min(build(v,sp,ls,l,m),build(v,sp,ls+1,m+1,r));
}

int get(int *sp, int pos, int l, int r, int lq, int rq) {
    if(r<lq or rq<l) return INT_MAX;
    if(lq<=l and r<=rq) return sp[pos];
    
    int m = (l+r)/2, ls = 2*pos+1;
    return min(get(sp,ls,l,m,lq,rq),get(sp,ls+1,m+1,r,lq,rq));
}

int main() { _
    int n,q,l,r;
    cin >> n >> q;

    int v[n], sp[4*n];
    for(int i=0;i<n;i++) cin >> v[i];

    build(v,sp,0,0,n-1);

    while(q--) {
        cin >> l >> r;
        l--;
        r--;

        cout << get(sp,0,0,n-1,l,r) << '\n';
    }
    
    return 0;
}
