#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,s;
    cin >> n >> s;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());

    int ans = min(abs(v[0]-s)+v[n-1]-v[0],abs(v[n-1]-s)+v[n-1]-v[0]);
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
