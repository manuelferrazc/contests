#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<pair<int,int>> ans;
bool ok = 0;

void dfs(vector<vector<int>> &adj, int v, int p=-1, bool sai = true) {
    // cout << (p==-1?-1:p+1) << " -> " << v+1 << ", " << sai << '\n';
    if(p==-1) {
        int u = adj[v][0];
        ans.push_back(make_pair(u,v));
        dfs(adj,u,v,true);
        
        u = adj[v][1];
        ans.push_back(make_pair(v,u));
        dfs(adj,u,v,false);

    } //else if(ok==false) {
        // for(int u:adj[v]) {
        //     if(u==p) continue;
        //     if(ok==false) {
        //         ok = true;
        //         ans.push_back(make_pair(v,u));
        //         dfs(adj,u,v,false);
        //         continue;
        //     }

        //     // if(sai) ans.push_back(make_pair(v,u));
        //     ans.push_back(make_pair(u,v));

        //     dfs(adj,u,v,true);
        // }
    else {
        for(int u:adj[v]) {
            if(u==p) continue;
            if(sai) ans.push_back(make_pair(v,u));
            else ans.push_back(make_pair(u,v));

            dfs(adj,u,v,not sai);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    ok = false;

    vector<vector<int>> adj(n);
    ans.clear();

    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    if(n==2) {
        cout << "NO\n";
        return;
    }

    bool okk = false;
    for(int i=0;i<n;i++) {
        if(adj[i].size()==2) {
            dfs(adj,i);
            okk = true;
            // cout << i+1 << '\n';
            break;
        }
    }
    
    if(okk==false) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(auto [a,b]:ans) cout << a+1 << ' ' << b+1 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
