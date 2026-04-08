#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n;
    cin >> n;

    int v[n];
    ll dp[n];
    
    for(int i=0;i<n;i++) {
        cin >> v[i];
        dp[i] = v[i];
    }

    if(n%2==0) for(int i=0;i<n;i++) dp[i]*=-1;

    for(int l = 2;l<=n;l++) {
        bool p = (l&1)==(n&1); // 1 se for vez do primeiro 

        ll dp2[n];


        for(int i=0;i+l<=n;i++) {
            if(p) dp2[i] = max(dp[i]+v[i+l-1],v[i]+dp[i+1]);
            else dp2[i] = min(dp[i]-v[i+l-1],-v[i]+dp[i+1]);
        }

        for(int i=0;i<n;i++) dp[i] = dp2[i];
    }

    cout << dp[0] << '\n';

    return 0;
}
