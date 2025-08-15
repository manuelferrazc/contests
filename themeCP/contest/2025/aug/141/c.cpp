#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int ddp(vector<vector<int>> &dp,vector<int> &a,vector<int> &b,vector<int> &c,int i,int mask) {
    if(dp[i][mask]!=-1) return dp[i][mask];
    if(i==0) {
        if(mask==1) return dp[i][mask] = a[0];
        else if(mask==2) return dp[i][mask] = b[0];
        else if(mask==4) return dp[i][mask] = c[0];
        else return dp[i][mask] = 0;
    }
    if(i==1 and mask==7) return dp[i][mask] = 0;

    dp[i][mask] = ddp(dp,a,b,c,i-1,mask);
    if(mask&1) dp[i][mask] = max(dp[i][mask],a[i]+ddp(dp,a,b,c,i-1,mask-1));
    if(mask&2) dp[i][mask] = max(dp[i][mask],b[i]+ddp(dp,a,b,c,i-1,mask-2));
    if(mask&4) dp[i][mask] = max(dp[i][mask],c[i]+ddp(dp,a,b,c,i-1,mask-4));
    
    return dp[i][mask];
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n),b(n),c(n);
    for(int &i:a) cin >> i;
    for(int &i:b) cin >> i;
    for(int &i:c) cin >> i;

    vector<vector<int>> dp(n,vector<int>(8,-1));
    
    for(int i=0;i<n;i++) dp[i][0] = 0;

    cout << ddp(dp,a,b,c,n-1,7) << '\n';
    
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
