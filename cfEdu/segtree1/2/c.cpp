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

void get(int pos, int l, int r, int x) {
    while(l!=r) {
        int m = (l+r)>>1;
        pos = 2*pos+1;
        if(seg[pos]>=x) r = m;
        else {
            pos++;
            l = m+1;
        }
    }
    cout << l << '\n';
}

int main() { _
    int n,q,op,a,b;
    cin >> n >> q;
    v.resize(n);
    for(auto &i:v) cin >> i;
    seg.resize(4*n);

    build(0,0,n-1);

    while(q--) {
        cin >> op >> a;

        if(op==1) {
            cin >> b;
            ::set(0,0,n-1,a,b);
        }
        else {
            if(seg[0]<a) cout << "-1\n";
            else get(0,0,n-1,a);
        }
    }
    return 0;
}
