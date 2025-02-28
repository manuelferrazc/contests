#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<bool> v;
vector<int> seg;

int build(int pos, int l, int r) {
    if(l==r) return seg[pos] = v[l];

    int m = (l+r)>>1;
    return seg[pos] =
        build(2*pos+1,l,m)+build(2*pos+2,m+1,r);
}

int set(int pos, int l, int r, int i) {
    if(i<l or r<i) return seg[pos];
    if(l==r) return seg[pos] = not seg[pos];

    int m = (l+r)>>1;
    return seg[pos] = ::set(2*pos+1,l,m,i)+::set(2*pos+2,m+1,r,i);
}

void get(int pos, int l, int r, int qtd) {
    if(l==r) {
        cout << l << '\n';
        return;
    }

    int m = (l+r)>>1, ls = 2*pos+1;
    if(seg[ls]<qtd) get(2*pos+2,m+1,r,qtd-seg[ls]);
    else get(ls,l,m,qtd);
}

int main() { _
    int n,q,op,p;
    cin >> n >> q;
    v.resize(n);
    seg.resize(n*4);
    bool b;
    for(int i=0;i<n;i++) {
        cin >> b;
        v[i] = b;
    }

    build(0,0,n-1);

    while(q--) {
        cin >> op >> p;

        if(op==1) ::set(0,0,n-1,p);
        else get(0,0,n-1,p+1);
    }

    return 0;
}
