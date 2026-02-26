#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int zero(int *st, int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return st[pos];
    if(st[pos]==0) return 0;
    if(l==r) return st[pos] = 0;

    int m = (l+r)>>1, ls = 2*pos+1;
    return st[pos] = max(zero(st,ls,l,m,lq,rq),zero(st,ls+1,m+1,r,lq,rq));
}

int get(int *st, int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return INT_MIN;
    if(lq<=l and r<=rq) return st[pos];

    int m = (l+r)>>1, ls = 2*pos+1;
    return max(get(st,ls,l,m,lq,rq),get(st,ls+1,m+1,r,lq,rq));
}

int sett(int *st, int pos, int l, int r, int i, int x) {
    if(l==r) return st[pos] = x;

    int m = (l+r)>>1, ls = 2*pos+1;
    if(i<=m) return st[pos] = max(sett(st,ls,l,m,i,x),st[ls+1]);
    else return st[pos] = max(st[ls],sett(st,ls+1,m+1,r,i,x));
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int *stl = new int[4*(n+2)];
    int *str = new int[4*(n+2)];
    for(int i=0;i<4*(n+2);i++) stl[i] = 0;
    for(int i=0;i<4*(n+2);i++) str[i] = 0;

    int ans[n];

    for(int i=n-1;i>=0;i--) {
        int x = get(str,0,0,n+1,v[i],n+1);
        ans[i] = x+1;

        zero(str,0,0,n+1,0,v[i]);
        sett(str,0,0,n+1,v[i],x+1);
    }

    // for(int i=0;i<n;i++) cout << ans[i] << ' ';
    // cout << '\n';

    for(int i=0;i<n;i++) {
        int x = get(stl,0,0,n+1,v[i],n+1);
        // cout << v[i] << ' ' << n+1 << '\n';
        ans[i] += x;
        
        zero(stl,0,0,n+1,0,v[i]);
        
        sett(stl,0,0,n+1,v[i],x+1);
    }

    // for(int i=0;i<n;i++) cout << ans[i] << ' ';
    // cout << '\n';

    cout << n-*max_element(ans,ans+n) << '\n';

    delete[] stl;
    delete[] str; 
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
