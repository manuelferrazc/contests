#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> v,st;

int build(int pos, int l, int r) {
    if(l==r) return st[pos] = v[l];
    int m=(l+r)>>1;
    return st[pos] = build(2*pos+1,l,m)|build(2*pos+2,m+1,r);
}

int get(int pos, int l, int r, int lq, int rq) {
    if(r<lq or rq<l) return 0;
    if(lq<=l and r<=rq) return st[pos];

    int m = (l+r)>>1;
    return get(2*pos+1,l,m,lq,rq)|get(2*pos+2,m+1,r,lq,rq);
}

bool check(int n, int x) {
    int q = get(0,0,n-1,0,x-1);

    for(int i=1;i+x<=n;i++) if(q!=get(0,0,n-1,i,i+x-1)) return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    v.resize(n);
    for(auto &i:v) cin >> i;
    st.resize(4*n);
    build(0,0,n-1);

    int l=1,r=n,ans=n;
    while(l<=r) {
        int m=(l+r)>>1;
        if(check(n,m)) {
            ans=m;
            r=m-1;
        } else l=m+1;
    }
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
