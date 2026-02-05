#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 500'000

vector<int> adj[MAX];
int id[MAX];
int id2[MAX];
int ant[MAX];
int lx=0;

void dfs(int v, int p) {
    id[v] = lx++;
    ant[v] = p;

    for(auto u:adj[v]) {
        if(u==p) continue;
        dfs(u,v);
    }

    id2[v] = lx-1;
}

int st[4*MAX];
int lazy[4*MAX]; // -1 -> seta pra 0, 1 -> seta pra 1, 0 -> nop

void prop(int pos, int l, int r) {
    if(lazy[pos]) {
        if(lazy[pos]==1) st[pos] = r-l+1;
        else st[pos] = 0;

        if(l!=r) lazy[2*pos+1] = lazy[2*pos+2] = lazy[pos];
    }

    lazy[pos] = 0;
}

int get(int pos, int l, int r, int lq, int rq) {
    prop(pos,l,r);
    if(rq<l or r<lq) return 0;
    if(lq<=l and r<=rq) return st[pos];

    int m = (l+r)/2,ls = 2*pos+1;
    return get(ls,l,m,lq,rq)+get(ls+1,m+1,r,lq,rq);
}

int sett(int pos, int l, int r, int lq, int rq, int x) {
    prop(pos,l,r);
    if(rq<l or r<lq) return st[pos];
    if(lq<=l and r<=rq) {
        lazy[pos] = x;
        prop(pos,l,r);
        return st[pos];
    }

    int m = (l+r)/2,ls = 2*pos+1;
    return st[pos] = sett(ls,l,m,lq,rq,x)+sett(ls+1,m+1,r,lq,rq,x);
}

int main() { _
    int n;
    cin >> n;
    
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,0);

    int q;
    cin >> q;
    while(q--) {
        int op,v;
        cin >> op >> v;
        v--;

        if(op==1) {
            int f = get(0,0,n-1,id[v],id2[v]);

            if(f!=(id2[v]-id[v]+1)) sett(0,0,n-1,id[ant[v]],id[ant[v]],-1);
            sett(0,0,n-1,id[v],id2[v],1);
        } else if(op==2) sett(0,0,n-1,id[v],id[v],-1);
        else {
            int f = get(0,0,n-1,id[v],id2[v]);
            cout << (f==(id2[v]-id[v]+1)) << '\n';
        }
    }
    
    return 0;
}
