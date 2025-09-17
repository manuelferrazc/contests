#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int *v, *st;

int build(int pos, int l, int r) {
    if(l==r) return st[pos] = 1;
    int m = (l+r)>>1, ls = 2*pos+1;
    return st[pos] = build(ls,l,m)+build(ls+1,m+1,r);
}

int find(int pos, int l, int r, int k) {
    if(l==r) return l;
    
    int m = (l+r)>>1, ls = 2*pos+1;
    if(st[ls]<k) return find(ls+1,m+1,r,k-st[ls]);
    return find(ls,l,m,k);
}

int zero(int pos, int l, int r, int i) {
    if(i<l or r<i) return st[pos];
    if(l==r) return st[pos] = 0;
    int m = (l+r)>>1, ls = 2*pos+1;
    return st[pos] = zero(ls,l,m,i)+zero(ls+1,m+1,r,i);
}

int main() { _
    int n;
    cin >> n;

    v = new int[n];
    st = new int[4*n];

    for(int i=0;i<n;i++) cin >> v[i]; 

    build(0,0,n-1);

    for(int i=0;i<n;i++) {
        int p;
        cin >> p;
        
        int ans = find(0,0,n-1,p);
        cout << v[ans] << ' ';

        zero(0,0,n-1,ans);
    }

    cout << '\n';

    delete[] v;
    delete[] st;
    
    return 0;
}
