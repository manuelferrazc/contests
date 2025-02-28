#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<unsigned> v, seg;

unsigned build(int pos, int l, int r) {
    if(l==r) return seg[pos] = v[l];

    int m = (l+r)>>1;
    return seg[pos] =
        max(build(2*pos+1,l,m),build(2*pos+2,m+1,r));
}

unsigned set(int pos, int l, int r, int i, int x) {
    if(i<l or r<i) return seg[pos];
    if(l==r) return seg[pos] = x;

    int m = (l+r)>>1;
    return seg[pos] = 
        max(::set(2*pos+1,l,m,i,x),::set(2*pos+2,m+1,r,i,x));
}

bool get(int pos, int l, int r, unsigned x, int b) {
    if(r<b or seg[pos]<x) return false;
    if(l==r) {
        cout << l << '\n';
        return true;
    }

    int m = (l+r)>>1, ls = 2*pos+1;
    if(seg[ls]>=x and get(ls,l,m,x,b)) return true;
    else return get(ls+1,m+1,r,x,b);
}

int main() { _
    unsigned n,q,op,a,b;
    cin >> n >> q;
    v.resize(n);
    for(auto &i:v) cin >> i;
    seg.resize(4*n);

    build(0,0,n-1);

    while(q--) {
        cin >> op >> a >> b;

        if(op==1) ::set(0,0,n-1,a,b);
        else if(not get(0,0,n-1,a,b)) cout << "-1\n";
    }
    return 0;
}
