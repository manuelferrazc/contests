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
    vector<int[2]> dp(n);
    vector<int> v(n);
    for(int &i:v) cin >> i;
    dp.back()[0] = 1;
    dp.back()[1] = 2;

    for(int i=n-2;i>=0;i--) {
        if(v[i]==1) {
            dp[i][0] = dp[i+1][1];
            dp[i][1] = dp[i+1][0];
        } else {
            dp[i][0] = 1;
            dp[i][1] = 2;
        }
    }

    if(dp[0][0]==1) cout << "First\n";
    else cout << "Second\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
