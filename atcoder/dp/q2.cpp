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

    int h[n];
    for(int i=0;i<n;i++) cin >> h[i];

    ll b[n];
    for(int i=0;i<n;i++) cin >> b[i];
    
    ll dp[n];
    for(int i=n-1;i>=0;i--) {
        dp[i] = 0;
        for(int j=i+1;j<n;j++) if(h[i]<h[j]) dp[i] = max(dp[i],dp[j]);
        dp[i] += b[i];
    }

    cout << *max_element(dp,dp+n) << '\n';

    return 0;
}
