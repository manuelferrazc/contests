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
    
    if(n==1) {
        cout << "1\n";
        return 0;
    }

    double prob[n][n], ans = 0;
    
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> prob[i][j];

    int v[n];
    iota(v,v+n-1,1);
    double dp[n];
    v[n-1] = 0;
    do {
        dp[v[0]] = prob[v[0]][v[1]];
        dp[v[1]] = prob[v[1]][v[0]];
        for(int i=2;i<n;i++) {
            dp[v[i]] = 0;
            for(int j=0;j<i;j++) dp[v[i]]+=dp[v[j]]*prob[v[i]][v[j]];
            for(int j=0;j<i;j++) dp[v[j]]*=prob[v[j]][v[i]];
        }
        ans = max(ans,dp[0]);
    } while(next_permutation(v,v+n-1));

    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}
