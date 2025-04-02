#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,m,dm;

int bfs(vector<string> &v, queue<pair<int,int>> &q, vector<vector<int>> &dist) {
    static const pair<int,int> d[] = {{1,0},{-1,0},{0,1},{0,-1}};
    int r=0;
    while(not q.empty()) {
        auto p = q.front();
        q.pop();
        r++;
        if(dist[p.ff][p.ss]==dm) continue;

        for(auto e:d) {
            int x=p.ff+e.ff, y=p.ss+e.ss;
            if(x<0 or y<0 or x>=n or y>=m or v[x][y]=='#' or dist[x][y]<=dist[p.ff][p.ss]+1) continue;
            dist[x][y] = dist[p.ff][p.ss]+1;
            q.push({x,y});
        }
    }

    return r;
}

int main() { _
    cin >> n >> m >> dm;
    vector<string> v(n);
    for(auto &i:v) cin >> i;
    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    queue<pair<int,int>> q;

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        if(v[i][j]=='H') {
            dist[i][j] = 0;
            q.push({i,j});
        }
    }

    cout << bfs(v,q,dist) << '\n';
    
    return 0;
}
