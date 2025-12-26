#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int v[200'000];
int st[800'000];

int build(int pos, int l, int r) {
    if(l==r) return st[pos] = v[l];

    int m = (l+r)>>1, ls = 2*pos+1;
    return st[pos] = max(build(ls,l,m),build(ls+1,m+1,r));
}

int get(int pos, int l, int r, int x) {
    while(l<r) {
        int m = (l+r)>>1, ls = 2*pos+1;
        if(st[ls]>=x) {
            pos = ls;
            r = m;
        } else {
            pos = ls+1;
            l = m+1;
        }
    }
    
    return l;
}

int change(int pos, int l, int r, int i, int x) {
    if(l==r) return st[pos]-=x;

    int m = (l+r)>>1, ls = 2*pos+1;
    if(i<=m) return st[pos] = max(change(ls,l,m,i,x),st[ls+1]);
    else return st[pos] = max(st[ls],change(ls+1,m+1,r,i,x));
}

int main() { _
    int n,q;
    cin >> n >> q;

    for(int i=0;i<n;i++) cin >> i[v];
    build(0,0,n-1);

    int ans[q];
    for(int i=0;i<q;i++) {
        int s;
        cin >> s;

        if(st[0]<s) i[ans] = 0;
        else {
            int id = get(0,0,n-1,s);
            i[ans] = id+1;

            change(0,0,n-1,id,s);
        }
    }

    for(int i=0;i<q;i++) cout << i[ans] << ' ';
    cout << '\n';

    return 0;
}
