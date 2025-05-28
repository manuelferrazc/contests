#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,m;
    cin >> n >> m;

    vector<int> a(n+1),b(m+1);
    for(int i=0;i<n;i++) cin >> a[i+1];
    for(int i=0;i<m;i++) cin >> b[i+1];
    vector<vector<pair<int,pair<int,int>>>> dp(n+1,vector<pair<int,pair<int,int>>>(m+1,make_pair(0,make_pair(0,0))));

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(a[i]==b[j] and dp[i-1][j-1].ff+1>dp[i][j].ff) {
                dp[i][j].ff = dp[i-1][j-1].ff+1;
                dp[i][j].ss.ff = i;
                dp[i][j].ss.ss = j;
            }
        }
    }

    b.clear();
    
    int x = dp.back().back().ss.ff,y=dp.back().back().ss.ss;

    while(x>0 and y>0) {
        b.push_back(a[x]);
        ll aux = x;
        x = dp[aux-1][y-1].ss.ff;
        y = dp[aux-1][y-1].ss.ss;
    }

    cout << b.size() << '\n';
    for(auto it = b.rbegin();it!=b.rend();it++) cout << *it << ' ';
    cout << '\n';

    return 0;
}
