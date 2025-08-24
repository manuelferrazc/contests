#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct st {
    int x;
    int y;
    bool inv;

    st(int _x, int _y, bool _inv) {
        x = _x;
        y = _y;
        inv = _inv;
    }
};

int main() { _
    int n,m;
    cin >> n >> m;

    vector<string> v(n);
    for(string &s:v) cin >> s;

    queue<st> q;
    pair<int,int> s,e;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]=='S') {
                s.ff = i;
                s.ss = j;
            } else if(v[i][j]=='G') {
                e.ff = i;
                e.ss = j;
            }
        }
    }

    q.push(st(s.ff,s.ss,false));
    vector<vector<vector<int>>> dist(n,vector<vector<int>>(m,{INT_MAX,INT_MAX}));
    dist[s.ff][s.ss][0] = 0;

    const pair<int,int> d[4] = {{1,0},{-1,0},{0,1},{0,-1}};

    while(not q.empty()) {
        auto [xx,yy,inv] = q.front();
        q.pop();

        for(auto const &dd:d) {
            int x = xx+dd.ff, y = yy+dd.ss;
            if(x<0 or x>=n or y<0 or y>=m or v[x][y]=='#') continue;

            if(v[x][y]=='.' or v[x][y]=='G' or v[x][y]=='S') {
                if(dist[x][y][inv]==INT_MAX) {
                    dist[x][y][inv] = dist[xx][yy][inv]+1;
                    q.push(st(x,y,inv));
                }
            } else if((v[x][y]=='o' and inv==false) or (v[x][y]=='x' and inv)) {
                if(dist[x][y][inv]==INT_MAX) {
                    dist[x][y][inv] = dist[xx][yy][inv]+1;
                    q.push(st(x,y,inv));
                }
            } else if(v[x][y]=='?') {
                if(dist[x][y][not inv]==INT_MAX) {
                    dist[x][y][not inv] = dist[xx][yy][inv]+1;
                    q.push(st(x,y,not inv));
                }
            }
        }
    }

    int ans = min(dist[e.ff][e.ss][0],dist[e.ff][e.ss][1]);
    if(ans==INT_MAX) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}
