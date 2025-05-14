#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n;
    cin >> n;
    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    dist[0][0] = 0;

    pair<int,int> d[] = {make_pair(2,1),make_pair(2,-1),
                        make_pair(-2,1),make_pair(-2,-1),
                        make_pair(1,2),make_pair(1,-2),
                        make_pair(-1,2),make_pair(-1,-2)};
    
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));

    while(not q.empty()) {
        auto t = q.front();
        q.pop();

        for(auto [xd,yd]:d) {
            int x = t.ff+xd,y=t.ss+yd;
            if(x<0 or y<0 or x>=n or y>=n or dist[x][y]!=INT_MAX) continue;
            dist[x][y] = dist[t.ff][t.ss]+1;
            q.push(make_pair(x,y));
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cout << dist[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
