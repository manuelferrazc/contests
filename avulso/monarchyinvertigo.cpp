#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int lx=0;

void dfs(vector<vector<int>> &adj, vector<pair<int,int>> &id, int v) {
    id[lx].ff = v;
    id[v].ss = lx++;

    for(int u:adj[v]) dfs(adj,id,u);
}

int sett(vector<int> &st, int pos, int l, int r, int i) {
    if(i<l or r<i) return st[pos];
    if(l==r) return st[pos] = 0;
    int m = (l+r)>>1,ls = 2*pos+1;
    return st[pos] = max(sett(st,ls,l,m,i),sett(st,ls+1,m+1,r,i));
}

int find(vector<int> &st, int pos, int l, int r) {
    if(l==r) return l;
    int m = (l+r)>>1,ls = 2*pos+1;
    if(st[ls]) return find(st,ls,l,m);
    return find(st,ls+1,m+1,r);
}

int main() { _
    vector<vector<int>> adj(1);
    int q;
    cin >> q;
    vector<pair<int,int>> qr(q);

    for(int i=0;i<q;i++) {
        cin >> qr[i].ff >> qr[i].ss;
        if(qr[i].ff==1) {
            adj[qr[i].ss-1].push_back(adj.size());
            adj.push_back(vector<int>());
        }
    }

    vector<int> st(adj.size()<<2,1);
    vector<pair<int,int>> id(adj.size());
    dfs(adj,id,0);

    for(int i=0;i<q;i++) {
        if(qr[i].ff==1) continue;
        
        sett(st,0,0,adj.size()-1,id[qr[i].ss-1].ss);
        int idx = find(st,0,0,adj.size()-1);
        cout << id[idx].ff+1 << '\n';
    }

    return 0;
}
