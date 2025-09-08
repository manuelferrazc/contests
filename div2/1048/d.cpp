#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int build(vector<int> &st, vector<int> &v, int pos, int l, int r) {
    if(l==r) return st[pos] = v[l];
    int m = (l+r)>>1, ls = 2*pos+1;
    return st[pos] = min(build(st,v,ls,l,m),build(st,v,ls+1,m+1,r));
}

int get(vector<int> &st, int pos, int l, int r, int lq, int rq) {
    if(r<lq or rq<l) return INT_MAX;
    if(lq<=l and r<=rq) return st[pos];
    int m = (l+r)>>1, ls = 2*pos+1;
    return min(get(st,ls,l,m,lq,rq),get(st,ls+1,m+1,r,lq,rq));
}

int Set(vector<int> &st, int pos, int l, int r, int i, int x) {
    if(r<i or i<l) return st[pos];
    if(l==r) return st[pos] = x;
    int m = (l+r)>>1, ls = 2*pos+1;
    return st[pos] = min(Set(st,ls,l,m,i,x),Set(st,ls+1,m+1,r,i,x));
}

void solve() {
    int n,q;
    cin >> n >> q;

    vector<int> v(n), pos(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        v[i]--;
        pos[v[i]] = i;
    }

    // d guarda a primeira posicao menor q i
    vector<int> d(n,INT_MAX);

    // s guarda as posições dos menores q i
    set<int> s;

    for(int i=0;i<n;i++) {
        auto it = s.lower_bound(pos[i]);
        if(it!=s.end()) d[i] = *it;
        s.insert(pos[i]);
    }

    s.clear();
    //
    vector<int> t(n,INT_MAX);
    vector<int> st(4*n,INT_MAX);

    for(int i=0;i<n;i++) {
        auto it = get(st,0,0,n-1,pos[i],n-1);
        if(it!=INT_MAX) t[i] = it;
        if(d[i]!=INT_MAX) {
            Set(st,0,0,n-1,pos[i],d[i]);
        }
    }

    for(int i=0;i<n;i++) {
        v[pos[i]] = t[i];
    }

    t.clear();
    t.resize(4*n);
    build(t,v,0,0,n-1);

    while(q--) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        if(get(t,0,0,n-1,a,b)>b) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}