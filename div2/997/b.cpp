#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    list<int> l;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) l.push_back(i);

    vector<string> v(n);
    for(auto &i:v) cin >> i;
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--) {
        int c=0;
        for(int j=0;j<i;j++) if(v[i][j]=='1') c++;
        // cout << c << ' ';
        auto it = next(l.begin(),c);
        ans[i] = *it;
        l.erase(it);
    }
    // cout << '\n';
    for(int i=0;i<n;i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
