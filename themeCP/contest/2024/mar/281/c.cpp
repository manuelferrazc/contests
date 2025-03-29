#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;
string s[2];
const pair<int,int> dd[] = {{1,0},{-1,0},{0,-1},{0,1}};

bool dfs(vector<pair<bool,bool>> &v,int x, int y) {
    if(x==n-1 or (x==n-2 and y==1)) return true;
    if(y) v[x].ss = true;
    else v[x].ff = true;

    for(auto d:dd) {
        int xx = x+d.ff, yy = y+d.ss;
        if(yy<0 or yy>=2 or xx<0 or xx>=n) continue;
        if(yy and xx==n-1) return true;
        if(yy) {
            if(s[1][xx]=='<') xx--;
            else xx++;
            if(v[xx].ss) continue;
            if(dfs(v,xx,yy)) return true;
        } else {
            if(s[0][xx]=='<') xx--;
            else xx++;
            if(v[xx].ff) continue;
            if(dfs(v,xx,yy)) return true;
        }
    }

    return false;
}

void solve() {
    cin >> n;
    cin >> s[0] >> s[1];

    vector<pair<bool,bool>> v(n,make_pair(false,false));

    if(dfs(v,0,0)) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
