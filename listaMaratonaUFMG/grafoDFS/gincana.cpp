#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define ff first
#define ss second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef set<int> si;

void dfs(int n, vb &v, vvi &adj) {
    v[n] = true;
    for(auto i:adj[n]) if(not v[i]) dfs(i,v,adj);
}

int main() { _
    int n, m, ans=0;
    cin >> n >> m;

    vvi adj(n+1,vi());
    vb v(n+1,false);

    int a,b;
    while(m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++) {
        if(not v[i]) {
            dfs(i,v,adj);
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
