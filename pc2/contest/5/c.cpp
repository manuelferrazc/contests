#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;
ll v[5000];

ll dp[5000][5000];

int main() { _
    cin >> n;
    for(int i=0;i<n;i++) cin >> v[i];

    for(int i=0;i<n;i++) for(int j=i;j<n;j++) dp[i][j] = -1;

    for(int size=0;size<n;size++) {
        for(int i=0;i+size<n;i++) {
            if(size==0) dp[i][i] = (n-size)*v[i];
            else 
                dp[i][i+size] = max(dp[i][i+size-1]+(n-size)*v[i+size],dp[i+1][i+size]+(n-size)*v[i]);
        }
    }

    cout << dp[0][n-1] << '\n';

    return 0;
}
