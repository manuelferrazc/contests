#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> adj[200'000];
int ans[200'000];
int c[200'000];

set<int> * dfs(int v, int p) {
    set<int> *r = new set<int>;
    r->insert(c[v]);

    for(int u:adj[v]) {
        if(u==p) continue;

        set<int> *x = dfs(u,v);
        if(r->size()<x->size()) swap(r,x);
        
        for(int i:*x) r->insert(i);
        delete x;
    }

    ans[v] = r->size();
    return r;
}

int main() { _
    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> c[i];
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    delete dfs(0,0);

    for(int i=0;i<n;i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
