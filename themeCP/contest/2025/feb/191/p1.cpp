#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n;
    cin >> n;
    pair<int,int> a,b,c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    a.x--;
    a.y--;
    b.x--;
    b.y--;
    c.x--;
    c.y--;

    vector<vector<bool>> vis(n,vector<bool>(n,false));
    vis[a.x][a.y] = true;
    vis[b.x][b.y] = true;
    for(int i=a.x+1;i<n;i++) vis[i][a.y] = true;
    for(int i=a.x-1;i>=0;i--) vis[i][a.y] = true;
    for(int i=a.y+1;i<n;i++) vis[a.x][i] = true;
    for(int i=a.y-1;i>=0;i--) vis[a.x][i] = true;

    for(int i=1;a.y+i<n and a.x+i<n;i++) vis[a.x+i][a.y+i]=true;
    for(int i=1;a.y+i<n and a.x-i>=0;i++) vis[a.x-i][a.y+i]=true;
    for(int i=1;a.y-i>=0 and a.x+i<n;i++) vis[a.x+i][a.y-i]=true;
    for(int i=1;a.y-i>=0 and a.x-i>=0;i++) vis[a.x-i][a.y-i]=true;
    
    queue<pair<int,int>> q;
    pair<int,int> dd[8] = {{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};

    q.push(b);

    while(not q.empty()) {
        auto p = q.front();
        q.pop();

        if(p.x == c.x and p.y==c.y) {
            cout << "YES\n";
            return 0;
        }

        for(auto &d:dd) {
            int x = p.x+d.x, y = p.y+d.y;
            if(x<0 or x>=n or y<0 or y>=n or vis[x][y]) continue;
            vis[x][y] = true;
            q.push(make_pair(x,y));
        }
    }

    cout << "NO\n";

    return 0;
}
