#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;

const pair<int,int> dd[4] = {{0,1},{1,0},{-1,0},{0,-1}};

int n;

int sit(int x, int y) {
    if(x%3==1 and y%3==1) return 1;
    if((x%3!=0) and (y%3!=0)) return 2;
    return 0;
}

void bfs(map<int,pair<int,int>> &tables,map<int,pair<int,int>> &sits) {
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
    q.push({0,{0,0}});
    set<pair<int,int>> vis;
    vis.insert({0,0});

    while(q.size()) {
        auto sla1 = q.top();
        q.pop();
        auto p = sla1.ss;

        int sla = sit(p.x,p.y);
        if(sla) {
            if(sla==1) tables.insert({(int)sits.size(),{p.x,p.y}});
            sits.insert({(int)sits.size(),{p.x,p.y}});
            continue;
        }

        for(auto d:dd) {
            int x = p.x+d.x,y=p.y+d.y;
            if(x<0 or y<0) continue;
            if(vis.count({x,y})) continue;
            vis.insert({x,y});
            q.push({sla1.ff+1,{x,y}});
        }

        if(tables.size()>=n) return;
    }
}

void solve() {
    cin >> n;
    map<int,pair<int,int>> tables;
    map<int,pair<int,int>> sits;

    bfs(tables,sits);
    for(int i=0;i<n;i++) {
        int sla;
        cin >> sla;
        if(sla) {
            auto it = sits.begin();
            cout << it->ss.x << ' ' << it->ss.y << '\n';
            tables.erase(it->ff);
            sits.erase(it);
        } else {
            auto it = tables.begin();
            cout << it->ss.x << ' ' << it->ss.y << '\n';
            sits.erase(it->ff);
            tables.erase(it);
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
