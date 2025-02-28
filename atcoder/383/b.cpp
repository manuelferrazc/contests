#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define x first
#define ss second
#define y second
typedef long long ll;
typedef unsigned long long ull;

int n,m,d;
vector<string> v;

int bfs(pair<int,int> p1, pair<int,int> p2) {
    int r=0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) 
        if(v[i][j]=='.' and (abs(p1.x-i)+abs(p1.y-j)<=d or abs(p2.x-i)+abs(p2.y-j)<=d)) r++;
    
    return r;
}

int main() { _
    cin >> n >> m >> d;
    v.resize(n);
    for(auto &s:v) cin >> s;

    int ans = INT_MIN;

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        if(v[i][j]=='#') continue;
        for(int ip = 0;ip<n;ip++) for(int jp=0;jp<m;jp++) 
            if(v[ip][jp]=='.') ans = max(ans,bfs({i,j},{ip,jp}));
    }

    cout << ans << '\n';

    return 0;
}
