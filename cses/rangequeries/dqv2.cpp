#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int st[800'000];

void build() {
    for(int i=0;i<800'000;i++) i[st] = INT_MAX;
}

int get(int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return INT_MAX;
    if(lq<=l and r<=rq) return st[pos];

    int m = (l+r)>>1, ls = 2*pos+1;
    return min(get(ls,l,m,lq,rq),get(ls+1,m+1,r,lq,rq));
}

int change(int pos, int l, int r, int i, int x) {
    if(l==r) return st[pos] = x;
    int m = (l+r)>>1, ls = 2*pos+1;

    if(i<=m) st[pos] = min(change(ls,l,m,i,x),st[ls+1]);
    else st[pos] = min(st[ls],change(ls+1,m+1,r,i,x));
    return st[pos];
}

int main() { _
    build();
    int n,q;
    cin >> n >> q;

    int v[n];

    map<int,set<int>> m;
    for(int i=0;i<n;i++) {
        cin >> i[v];
        m[i[v]].insert(i);
    }

    for(auto &[lx,ids]:m) {
        auto it = prev(ids.end());

        while(it!=ids.begin()) {
            auto it2 = it;
            it--;
            change(0,0,n-1,*it,*it2);
        }
    }

    int op,a,b;
    
    while(q--) {
        cin >> op >> a >> b;
        a--;

        if(op==1) {
            auto it = m[v[a]].lower_bound(a);
            if(it!=m[v[a]].begin()) {
                if(it!=prev(m[v[a]].end())) change(0,0,n-1,*prev(it),*next(it));
                else change(0,0,n-1,*prev(it),INT_MAX);
            }
            m[v[a]].erase(a);
            if(m[v[a]].empty()) m.erase(v[a]);

            v[a] = b;
            it = m[v[a]].lower_bound(a);
            if(it!=m[v[a]].end()) change(0,0,n-1,a,*it);
            else change(0,0,n-1,a,INT_MAX);

            if(it!=m[v[a]].begin()) change(0,0,n-1,*prev(it),a);

            m[v[a]].insert(a);
        } else {
            b--;
            if(get(0,0,n-1,a,b)>b) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
    return 0;
}
