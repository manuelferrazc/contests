#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;

int n,m;

unsigned bfs(vector<vector<unsigned>> &v, pair<int,int> start) {
    unsigned r=v[start.x][start.y];
    v[start.x][start.y]=0;

    queue<pair<int,int>> q;
    q.push(start);
    const pair<int,int> dd[4] = {{1,0},{-1,0},{0,1},{0,-1}};

    while(not q.empty()) {
        pair<int,int> p = q.front();
        q.pop();

        for(auto const &d:dd) {
            int x=p.x+d.x, y=p.y+d.y;
            if(x<0 or x>=n or y<0 or y>=m or v[x][y]==0U) continue;
            r+=v[x][y];
            v[x][y]=0;
            q.push(make_pair(x,y)); 
        }
    }

    return r;
}

void solve() {
    cin >> n >> m;
    vector<vector<unsigned>> v(n,vector<unsigned>(m));

    for(auto &i:v) 
        for(auto &j:i) cin >> j;
    
    unsigned ans = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]) ans = max(ans,bfs(v,make_pair(i,j)));
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
