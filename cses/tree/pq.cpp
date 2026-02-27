#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> adj[200'000];

int lx=0;
int t[200'000];
int out[200'000];

void dfs(int v, int p) {
    t[v] = lx++;

    for(int u:adj[v]) {
        if(u!=p) dfs(u,v);
    }
    out[v] = lx++;
}

ll st[1'600'000];

ll build(int *v, int pos, int l, int r) {
    if(l==r) return st[pos] = v[l];
    int m = (l+r)>>1, ls = 2*pos+1;
    return st[pos] = build(v,ls,l,m)+build(v,ls+1,m+1,r);
}

ll change(int pos, int l, int r, int i, int x) {
    if(l==r) return st[pos] = x;
    
    int m = (l+r)>>1, ls = 2*pos+1;
    
    if(i<=m) return st[pos] = change(ls,l,m,i,x)+st[ls+1];
    else return st[pos] = st[ls] + change(ls+1,m+1,r,i,x);
}

ll get(int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return 0;
    if(lq<=l and r<=rq) return st[pos];

    int m = (l+r)>>1, ls = 2*pos+1;
    return get(ls,l,m,lq,rq)+get(ls+1,m+1,r,lq,rq);
}

int main() { _
    int n,q,a,b,op;
    cin >> n >> q;

    int v[n];
    for(int i=0;i<n;i++) cin >> i[v];

    for(int i=1;i<n;i++) {
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(0,-1);

    {
        int v2[2*n];
        for(int i=0;i<n;i++) v2[t[i]] = v[i];
        for(int i=0;i<n;i++) v2[out[i]] = -v[i];
        build(v2,0,0,2*n-1);
    }

    while(q--) {
        cin >> op >> a;
        a--;

        if(op==1) {
            cin >> b;
            change(0,0,2*n-1,t[a],b);
            change(0,0,2*n-1,out[a],-b);
        } else cout << get(0,0,2*n-1,0,t[a]) << '\n';
    }

    return 0;
}
