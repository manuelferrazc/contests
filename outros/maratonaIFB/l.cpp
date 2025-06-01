#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

int n,m;

pii d[] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(vs &v, vector<vb> &vi, int x, int y) {
    if(x<0 or y<0 or x==n or y==m or vi[x][y] or v[x][y]=='#') return;
    vi[x][y] = true;

    for(auto p:d) 
        dfs(v,vi,x+p.ff,y+p.ss);
}

int main() { _
    cin >> n >> m;

    vs v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vb> vis(n,vb(m,false));
    int ans=0;

    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        if(not vis[i][j] and v[i][j]=='F') {ans++;dfs(v,vis,i,j);}

    cout << ans << '\n';
    return 0;
}
