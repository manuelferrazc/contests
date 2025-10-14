#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const pair<int,int> d[] = {{1,0},{-1,0},{0,1},{0,-1}};

int bfs(vector<vector<int>> &dist, int sx, int sy) {
    int qtd=0;
    queue<pair<int,int>> q;
    dist[sx][sy] = -1;
    q.push({sx,sy});

    while(q.size()) {
        qtd++;
        auto [a,b] = q.front();
        q.pop();

        for(auto [dx,dy]:d) {
            int x=a+dx,y=b+dy;
            // cout << x << ' ' << y << '\n';
            if(dist[x][y]==INT_MAX) {
                q.push({x,y});
                dist[x][y] = -1;
            }
        }
    }

    return qtd;
}

void solve() {
    int n,m,s;
    cin >> n >> m >> s;

    string v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    queue<pair<int,int>> q;

    for(int i=0;i<n;i++) {
        if(v[i][0]=='.') {
            q.push({i,0});
            dist[i][0] = 1;
        } else dist[i][0] = 0;
        if(v[i][m-1]=='.') {
            q.push({i,m-1});
            dist[i][m-1] = 1;
        } else dist[i][m-1] = 0;
    }

    for(int i=1;i<m-1;i++) {
        if(v[0][i]=='.') {
            q.push({0,i});
            dist[0][i] = 1;
        } else dist[0][i] = 0;
        if(v[n-1][i]=='.') {
            q.push({n-1,i});
            dist[n-1][i] = 1;
        } else dist[n-1][i] = 0;
    }


    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]=='#') {
                for(auto [a,b]:d) {
                    int x = i+a,y=j+b;

                    if(x>=0 and x<n and y>=0 and y<m and dist[x][y]==INT_MAX) {
                        if(v[x][y]=='.') {
                            q.push({x,y});
                            dist[x][y] = 1;
                        } else dist[x][y] = 0;
                    }
                }
                dist[i][j] = 0;
            }
        }
    }

    while(q.size()) {
        auto [a,b] = q.front();
        q.pop();

        if(dist[a][b]==s) break;

        for(auto [dx,dy]:d) {
            int x = a+dx,y=b+dy;
            if(x>=0 and x<n and y>=0 and y<m and dist[x][y]==INT_MAX and v[x][y]=='.') {
                q.push({x,y});
                dist[x][y] = 1+dist[a][b];
            }

        }
    }
    // cout << '\n';
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) cout << dist[i][j] << ' ';
    //     cout << '\n';
    // }

    int ans=0;
    for(int i=1;i<n-1;i++) {
        for(int j=1;j<m-1;j++) {

            if(dist[i][j]==INT_MAX) ans = max(ans,bfs(dist,i,j));
        }
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
