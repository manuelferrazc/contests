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
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> v[i][j];
    vector<int> ans(2*n,0);

    set<int> s;
    s.insert(1);
    for(int i=1;i<2*n;i++) {
        s.insert(i+1);
        if(i<n) ans[i] = v[i-1][0];
        else ans[i]=v[n-1][i%n];
    }
    for(int i=1;i<2*n;i++) s.erase(ans[i]);
    ans[0] = *s.begin();
    for(int i:ans) cout << i << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
