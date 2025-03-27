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

    vector<vector<int>> vl(n,vector<int>(m,0)), vc(n,vector<int>(m,0));

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]=='1') vl[i][j]++;
            else break;
        }
    }

    for(int j=0;j<m;j++) {
        for(int i=0;i<n;i++) {
            if(v[i][j]=='1') vc[i][j]++;
            else break;
        }
    }

    for(int i=1;i<n;i++) for(int j=1;j<m;j++) {
        if(v[i][j]=='1' and max(vl[i][j-1],vc[i-1][j])==0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
