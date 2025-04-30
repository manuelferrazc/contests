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
    vector<string> a(n),b(n);
    for(string &s:a) cin >> s;
    for(string &s:b) cin >> s;

    vector<vector<int>> ql(3,vector<int>(n,0)), qc(3,vector<int>(m,0));

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            ql[(a[i][j]-b[i][j]+3)%3][i]++;
            qc[(a[i][j]-b[i][j]+3)%3][j]++;
        }
    }

    for(int i=0;i<n;i++) if((ql[1][i]%3)!=ql[2][i]%3) {
        cout << "NO\n";
        return;
    }

    for(int i=0;i<m;i++) if((qc[1][i]%3)!=qc[2][i]%3) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
