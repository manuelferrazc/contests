#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int solve() {
    int n;
    cin >> n;

    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    bool ok = true;
    int g = v[0];

    for(int i=1;i<n;i++) {
        if(g!=v[i]) ok = false;
        g = gcd(g,v[i]);
    }

    if(ok) return 0;

    for(int i=0;i<n;i++) v[i]/=g;
    
    int *dp = new int[5001];

    dp[1] = 0;
    dp[0] = 100000;
    for(int i=2;i<=5000;i++) dp[i] = 100000;

    for(int j=0;j<n;j++) {
        int *dp2 = new int[5001];

        for(int i=1;i<=5000;i++) {
            dp2[i] = min(dp[i],1+dp[gcd(i,v[j])]);
        }

        delete[] dp;
        dp = dp2;
    }

    int k = -1;

    for(int i=0;i<n;i++) {
        if(k==-1 or dp[v[i]]<dp[v[k]]) k = i;
    }
    int ans = dp[v[k]];
    delete[] dp;
    v[k] = 1;
    
    sort(v,v+n);
        
    for(int i=n-1;v[i]>1;i--) ans++;

    return ans;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
