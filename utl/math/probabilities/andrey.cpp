#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct t {
    double z;
    double u;
    bool ok;

    t(): z(0), u(0), ok(false) {}

    t(double _z, double _u): z(_z), u(_u), ok(true) {}
};

int main() { _
    int n;
    cin >> n;

    double ans=0;
    vector<double> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];

    vector<vector<t>> dp(n+1,vector<t>(100+1));

    auto f2 = [&] (auto f,int i, int j) {
        if(j==0) {
            dp[i][j] = t(1,0);
            return;
        }
        if(i==1) {
            if(j!=1) dp[i][j] = t(0,0);
            else dp[i][j] = t(1-v[1],v[1]);
            return;
        }

        if(dp[i-1][j].ok==false) f(f,i-1,j);
        if(dp[i-1][j-1].ok==false) f(f,i-1,j-1);

        auto p1 = dp[i-1][j];
        auto p2 = dp[i-1][j-1];

        if(p1.u>=p2.u*(1-v[i])+p2.z*v[i]) dp[i][j] = p1;
        else dp[i][j] = t(p2.z*(1-v[i]),p2.u*(1-v[i])+p2.z*v[i]);

        dp[i][j].ok = true;
    };

    for(int i=1;i<=n;i++) {
        if(!dp[n][i].ok) f2(f2,n,i);
        ans = max(ans,dp[n][i].u);
    }

    cout << fixed << setprecision(15) << ans << '\n';

    return 0;
}
