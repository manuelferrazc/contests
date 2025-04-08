#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,m;
vector<string> v;
vector<string> init;
vector<vector<int>> ans;

int main() { _
    cin >> n >> m;
    v.resize(n);
    ans.resize(n,vector<int>(m,2));
    init.resize(n,string(m,'W'));
    for(auto &s:v) cin >> s;

    pair<int,int> dd[] = {{0,1},{0,-1},{1,0},{-1,0}};

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(auto d:dd) {
                int x=i+d.ff,y=j+d.ss;
                if(x<0 or y<0 or x>=n or y>=m) continue;
                init[x][y] = init[x][y]=='W'?'B':'W';
            }
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]!=init[i][j]) ans[i][j]=3;
        }
    }

    cout << "1\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cout << ans[i][j];
        cout << '\n';
    }

    return 0;
}
