#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
 
int main() { _
    int n, x;
    cin >> n >> x;
    
    pair<int,int> dp[1<<n];
    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    dp[0] = pair(0,x);

    for(int i=1;i<(1<<n);i++) {
        dp[i] = pair(INT_MAX,INT_MAX);

        for(int j=0;(1<<j)<=i;j++) {
            if(i&(1<<j)) {
                int m = i-(1<<j);

                if(dp[m].ff<dp[i].ff) {
                    if(dp[m].ff<=dp[i].ff-2) {
                        dp[i].ff = dp[m].ff;
                        if(dp[m].ss+v[j]<=x) dp[i].ss = dp[m].ss+v[j];
                        else {
                            dp[i].ff++;
                            dp[i].ss = v[j];
                        }
                    } else if(dp[m].ss+v[j]<=x) {
                        dp[i].ff = dp[m].ff;
                        dp[i].ss = dp[m].ss+v[j];
                    } else dp[i].ss = min(dp[i].ss,dp[m].ss+v[j]);
                } else if(dp[m].ff==dp[i].ff and dp[m].ss+v[j]<=x)
                    dp[i].ss = min(dp[i].ss,dp[m].ss+v[j]);
            }
        }
    }

    cout << dp[(1<<n)-1].ff << '\n';
 
    return 0;
}
