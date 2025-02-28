#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define nao '#'
#define sem '.'
#define com '@'

int main() { _
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    x--;
    y--;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    string t;
    cin >> t;
    int ans=0;
    map<char,pair<int,int>> d = {{'U',make_pair(-1,0)},{'D',make_pair(1,0)},{'R',make_pair(0,1)},{'L',make_pair(0,-1)}};

    for(ull i=0;i<t.size();i++) {
        auto p = d.at(t[i]);
        int xl = x+p.ff, yl = y+p.ss;
        if(v[xl][yl]=='#') continue;
        x = xl;
        y = yl;

        if(v[x][y]==com) {
            ans++;
            v[x][y] = sem;
        }
    }

    cout << x+1 << ' ' << y+1 << ' ' << ans << '\n';

    return 0;
}
