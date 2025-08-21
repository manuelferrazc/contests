#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

auto solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(n<=3) return 0;
    int f=0;
    int ans = n;
    for(int i=0;i<n;i++) if(adj[i].size()==1) f++;
    
    for(int i=0;i<n;i++) {
        int q=0;
        for(int v:adj[i]) if(adj[v].size()==1) q++;
        ans = min(ans,f-q);
    }

    return ans;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
