#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

long double dfs(vector<vector<int>> &adj,int v=0, int p=-1, long double d=1, int l=0) {
    if(adj[v].size()==1ULL and p!=-1) return l*d;
    long double r=0;
    if(p==-1) d /=adj[v].size();
    else d/=adj[v].size()-1.0;
    for(auto i:adj[v]) {
        if(i==p) continue;
        r+=dfs(adj,i,v,d,l+1);
    }
    return r;
}

int main() { _
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

    long double s=dfs(adj,0);
    cout << fixed << setprecision(20) << s << '\n';

    return 0;
}
