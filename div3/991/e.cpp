#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

ll ddp(vector<vector<ll>> &dp, string &a, string &b, string &c, ll i, ll j) {
    if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];
    if(i==-1 and j==-1) return 0;
    if(i==-1) return dp[i+1][j+1] = ddp(dp,a,b,c,i,j-1)+(c[j]!=b[j]);
    if(j==-1) return dp[i+1][j+1] = ddp(dp,a,b,c,i-1,j)+(c[i]!=a[i]);

    return dp[i+1][j+1] = min((c[i+j+1]!=a[i])+ddp(dp,a,b,c,i-1,j),(c[i+j+1]!=b[j])+ddp(dp,a,b,c,i,j-1));
}

void solve() {
    string a,b,c;
    cin >> a >> b >> c;
    vector<vector<ll>> dp(a.size()+1,vector<ll>(b.size()+1,-1));

    cout << ddp(dp,a,b,c,a.size()-1,b.size()-1) << '\n';
}

int main() { _
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
