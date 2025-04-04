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

    if(n==1) {
        cout << "YES\n13\n";
        return;
    }
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        if(i==j) continue;
        ans[i]&=v[i][j];
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(v[i][j] and v[i][j]!=(ans[i]|ans[j])) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for(int i=0;i<n;i++) cout << ans[i] << ' ';
    cout << '\n';
    
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
