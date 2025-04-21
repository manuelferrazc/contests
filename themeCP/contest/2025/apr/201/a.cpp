#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    cin >> n >> m;
    vector<string> v(n);
    for(string &s:v) cin >> s;

    pair<int,int> p=make_pair(-1,-1);
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]=='#') {
                p = make_pair(i,j);
                break;
            }
        }
        if(p.ff>=0) break;
    }

    auto e = p;
    for(;e.ff<n;e.ff++) {
        if(v[e.ff][e.ss]=='.') {
            break;
        }
    }
    e.ff--;

    cout << (e.ff+p.ff)/2+1 << ' ' << p.ss+1 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
