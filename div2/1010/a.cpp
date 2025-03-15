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
    for(auto &i:v) cin >> i;

    int ql=0,qr=0;
    for(int i=0;i<n;i++) {
        int s=0;
        for(int j=0;j<m;j++) if(v[i][j]=='1') s++;
        if(s&1) ql++;
    }

    for(int j=0;j<m;j++) {
        int s=0;
        for(int i=0;i<n;i++) if(v[i][j]=='1') s++;
        if(s&1) qr++;
    }

    cout << max(ql,qr) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
