#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(string &s:v) cin >> s;

    if(v[0][0]==v.back().back() or v[n-1][0]==v[0][m-1]) {
        cout << "YES\n";
        return;
    }

    bool b1=false,b2=false;
    for(int i=1;i<n and not b1;i++) if(v[0][0]!=v[i][0]) b1=true;
    for(int i=1;i<m and not b2;i++) if(v[0][0]!=v[0][i]) b2=true;

    if(b1 and b2) {
        cout << "YES\n";
        return;
    }

    b1=b2=false;
    for(int i=1;i<n and not b1;i++) if(v[0][m-1]!=v[i][m-1]) b1 = true;
    for(int i=0;i<m-1 and not b2;i++) if(v[0][m-1]!=v[0][i]) b2 = true;

    if(b1 and b2) {
        cout << "YES\n";
        return;
    }

    b1=b2=false;
    for(int i=0;i<n-1 and not b1;i++) if(v[n-1][0]!=v[i][0]) b1=true;
    for(int i=1;i<m and not b2;i++) if(v[n-1][0]!=v[n-1][i]) b2=true;

    if(b1 and b2) {
        cout << "YES\n";
        return;
    }

    b1=b2=false;
    for(int i=0;i<n-1 and not b1;i++) if(v[n-1][m-1]!=v[i][m-1]) b1 = true;
    for(int i=0;i<m-1 and not b2;i++) if(v[n-1][m-1]!=v[n-1][i]) b2 = true;

    if(b1 and b2) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
