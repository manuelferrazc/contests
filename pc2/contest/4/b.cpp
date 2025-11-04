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

    int v[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> v[i][j];

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if((i==0 or i==n-1) and (j==0 or j==m-1)) {
                if(v[i][j]>2) {
                    cout << "NO\n";
                    return;
                }
            } else if(i==0 or i==n-1 or j==0 or j==m-1) {
                if(v[i][j]>3) {
                    cout << "NO\n";
                    return;
                }
            } else {
                if(v[i][j]>4) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n2 ";

    for(int i=1;i<m-1;i++) cout << 3 << ' ';
    cout << 2 << '\n';

    for(int i=1;i<n-1;i++) {
        cout << 3 << ' ';
        for(int j=1;j<m-1;j++) cout << 4 << ' ';
        cout << 3 << '\n';
    }

    cout << 2 << ' ';
    for(int i=1;i<m-1;i++) cout << 3 << ' ';
    cout << 2 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
