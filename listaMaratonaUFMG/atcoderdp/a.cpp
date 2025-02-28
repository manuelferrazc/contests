#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define ff first
#define ss second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef set<int> si;

int main() { _
    int n;
    cin >> n;

    vi v(n);
    for(auto &i : v) cin >> i;

    vi dp(n);
    dp[0] = 0;
    dp[1] = abs(v[0]-v[1]);

    for(int i=2;i<n;i++) dp[i] = min(dp[i-1]+abs(v[i-1]-v[i]),dp[i-2]+abs(v[i-2]-v[i]));

    cout << dp.back() << '\n';

    return 0;
}
