#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll get(ll *sp, int a, int b) {
    if(a) return sp[b]-sp[a-1];
    return sp[b];
}

int main() { _
    int n;
    cin >> n;

    ll dp[n][n];
    for(int i=0;i<n;i++) dp[i][i] = 0;

    ll sp[n];
    cin >> sp[0];
    for(int i=1;i<n;i++) {
        int x;
        cin >> x;
        sp[i] = sp[i-1]+x;
    }

    for(int i=n-1;i>=0;i--) {
        for(int j=i+1;j<n;j++) {
            dp[i][j] = LLONG_MAX;
            for(int k=i;k<j;k++)
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+get(sp,i,k)+get(sp,k+1,j));
        }
    }

    cout << dp[0][n-1] << '\n';
    
    return 0;
}
