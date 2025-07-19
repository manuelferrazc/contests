#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool anyy(vector<bool> &b) {
    for(ull i=0;i<b.size();i++) if(b[i]) return true;
    return false;
}

int solve() {
    int n,m;
    cin >> n >> m;

    vector<string> a(n);
    for(string &s:a) cin >> s;
    vector<bool> b(n,true);
    vector<vector<string>> v(m,vector<string>(n));
    int mx=0;

    for(int i=0;i<m;i++) {
        int q=0;
        for(int j=0;j<n;j++) {
            cin >> v[i][j];
            if(v[i][j]==a[j]) {
                q++;
                b[j] = false;
            }
        }
        mx = max(mx,q);
    }

    if(anyy(b)) return -1;

    return n+2*(n-mx);
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
