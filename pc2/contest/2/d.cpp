

#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct st {
    int x;
    int y;
    int dist;

    st(int a, int b, int c) {
        x = a;
        y = b;
        dist = c;
    }
};

int free_c = 0;
int n,m,p;
const pair<int,int> dv[] = {{1,0},{-1,0},{0,1},{0,-1}};

bool bfs(string *v, vector<pair<int,int>> &pos, queue<st> &q, int &qtd) {
    bool r = false;
    while(not q.empty()) {
        auto [x,y,dist] = q.front();
        q.pop();
        if(dist==0) {
            pos.push_back({x,y});
            continue;
        }

        for(auto [dx,dy]:dv) {
            int xn = x+dx, yn = y+dy;
            if(xn>=n or yn>=m or xn<0 or yn<0) continue;
            if(v[xn][yn]=='.') {
                r = true;
                free_c--;
                v[xn][yn] = '[';
                qtd++;
                q.push(st(xn,yn,dist-1));
            }
        }
    }
    return r;
}

int main() { _
    cin >> n >> m >> p;

    int sp[p];
    for(int i=0;i<p;i++) cin >> sp[i];
    
    string v[n];
    for(string &x:v) cin >> x;
    
    vector<vector<pair<int,int>>> pos(p,vector<pair<int,int>>());
    vector<int> qtd(p,0);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]=='.') free_c++;
            else if(isdigit(v[i][j])) {
                pos[v[i][j]-'1'].push_back(pair<int,int>(i,j));
                qtd[v[i][j]-'1']++;
            }
        }
    }

    int q2=p;
    queue<st> q;
    for(int t=0;free_c and q2;t=(t+1)%p) {
        if(pos[t].empty()) continue;

        for(auto pp:pos[t]) q.push(st(pp.ff,pp.ss,sp[t]));
        pos[t].clear();

        while(not q.empty()) {
            auto [x,y,dist] = q.front();
            q.pop();
            if(dist==0) {
                pos[t].push_back({x,y});
                continue;
            }

            for(auto [dx,dy]:dv) {
                int xn = x+dx, yn = y+dy;
                if(xn>=n or yn>=m or xn<0 or yn<0) continue;
                if(v[xn][yn]=='.') {
                    free_c--;
                    v[xn][yn] = '[';
                    qtd[t]++;
                    q.push(st(xn,yn,dist-1));
                }
            }
        }
        if(pos[t].empty()) q2--;
    }

    for(int i=0;i<p;i++) cout << qtd[i] << ' ';
    cout << '\n';

    return 0;
}
