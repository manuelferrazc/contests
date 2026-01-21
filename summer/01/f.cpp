#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
#define ff first
#define ss second
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int st[320000];

void build(int pos, int l, int r) {
    st[pos] = 0;
    int ls = 2*pos+1,m = (l+r)/2;

    if(l!=r) {
        build(ls,l,m);
        build(ls+1,m+1,r);
    }
}

void prop(int pos, int l, int r) {
    int ls = 2*pos+1,m = (l+r)/2;

    if(st[pos] and l!=r) {
        st[ls] = st[pos];
        st[ls+1] = st[pos];
        st[pos] = 0;
    }

}

void update(int pos, int l, int r, int lq, int rq, int x) {
    prop(pos,l,r);

    int ls = 2*pos+1,m = (l+r)/2;
    if(rq<l or r<lq) return;
    if(lq<=l and r<=rq) {
        st[pos] = x;
        return;
    }

    update(ls,l,m,lq,rq,x);
    update(ls+1,m+1,r,lq,rq,x);
}

int get(int pos, int l, int r, int x) {
    prop(pos,l,r);

    if(l==r) return st[pos];
    int ls = 2*pos+1,m = (l+r)/2;
    if(x<=m) return get(ls,l,m,x);
    return get(ls+1,m+1,r,x);
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].ff >> v[i].ss;

    map<int,int> m;
    for(int i=0;i<n;i++) {
        m.insert({v[i].ff,-1});
        m.insert({v[i].ss,-1});
    }

    int x=0;
    for(auto it = m.begin();it!=m.end();it++) it->ss = x++;

    for(int i=0;i<n;i++) {
        v[i].ff = m[v[i].ff];
        v[i].ss = m[v[i].ss];
    }

    build(0,0,2*n-1);

    for(int i=0;i<n;i++) {
        update(0,0,2*n-1,v[i].ff,v[i].ss,i+1);
    }

    set<int> ans;
    for(int i=0;i<2*n;i++) {
        int x = get(0,0,2*n-1,i);
        // cout << i << ' ' << x << '\n';
        if(x) ans.insert(x);
    }

    cout << ans.size() << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
	exit(0);
}