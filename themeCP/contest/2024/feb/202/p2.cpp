#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for(auto &i:v) cin >> i;

    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n-i;j++) {
            char &c1 = v[i][j], &c2 = v[j][n-i-1], &c3 = v[n-i-1][n-j-1], &c4 = v[n-j-1][i];
            char c = max({c1,c2,c3,c4});
            ans+=c-c1;
            ans+=c-c2;
            ans+=c-c3;
            ans+=c-c4;
            c1=c2=c3=c4=c;
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
