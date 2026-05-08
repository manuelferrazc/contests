#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second

typedef long long ll;
#define int ll

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main() { _
    int n, K; cin >> n >> K;
    vector<int> v(n); for(auto& x: v) cin >> x;

    int suml[n][n], sumr[n][n]; memset(suml, 0, sizeof suml), memset(sumr, 0, sizeof sumr);
    for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++){
        for(int k = i+1; k <= j; k++) suml[i][j] += (k-i)*v[k];
        for(int k = j-1; k >= i; k--) sumr[i][j] += (j-k)*v[k];
    }

    int dp[K+1][n];
    for(int j = 0; j < K+1; j++) for(int k = 0; k < n; k++) dp[j][k] = LINF;

    dp[0][0] = dp[1][0] = 0;
    for(int i = 0; i < n; i++) for(int k = 1; k <= K; k++) for(int p = 0; p < i; p++){
        if(k == 1){
            dp[k][i] = sumr[0][i];
            continue;
        }

        int mid = (i+p)/2;
        int to_mid = suml[p][mid];
        int to_r = sumr[mid+1][i];

        dp[k][i] = min(dp[k][i], dp[k-1][p]+to_mid+to_r);
    }

    int ans = LINF;
    for(int i = 0; i < n; i++) ans = min(ans, dp[K][i]+suml[i][n-1]);
    cout << ans << endl;

    return 0;
}