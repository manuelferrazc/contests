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
    vector<string> s(n),t(m);
    for(auto &i:s) cin >> i;
    for(auto &i:t) cin >> i;

    for(int i=0;i+m<=n;i++) for(int j=0;j+m<=n;j++) {
        bool ok = true;
        for(int x=0;x<m;x++) {
            for(int y=0;y<m;y++) {
                if(s[i+x][j+y]!=t[x][y]) {
                    ok = false;
                    break;
                }
            }
            if(not ok) break;
        }
        if(ok) {
            cout << i+1 << ' ' << j+1 << '\n';
            return;
        }
    }
}

int main() { _
    solve();
    return 0;
}
