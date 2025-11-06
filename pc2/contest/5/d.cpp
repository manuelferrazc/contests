#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct Edge {
    short u,v;
    int w;

    Edge(short _u, short _v, int _w): u(_u), v(_v), w(_w) {}

};

struct cmp {
    bool operator()(const Edge e1, const Edge e2) {
        return e1.w>e2.w;
    }
};

int main() { _
    int n,m;
    cin >> n >> m;

    int v[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> v[i][j];

    priority_queue<Edge,vector<Edge>,cmp> pq;
    pq.push(Edge(0,0,v[0][0]));

    int dist[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) dist[i][j] = INT_MAX;
    dist[0][0] = v[0][0];

    pair<int,int> dd[] = {{0,1},{0,-1},{1,0}};

    while(pq.size()) {
        auto [x,y,w] = pq.top();
        pq.pop();

        if(w!=dist[x][y]) continue;
        if(x==n-1 and y==m-1) {
            cout << w << '\n';
            break;
        }
        for(auto [x2,y2]:dd) {
            short x1 = x2+x, y1=y2+y;
            if(x1<0 or x1>=n or y1<0 or y1>=m or dist[x1][y1]<=max(v[x1][y1],w)) continue;

            dist[x1][y1] = max(v[x1][y1],w);
            pq.push({Edge(x1,y1,dist[x1][y1])});
        }
    }

    return 0;
}
