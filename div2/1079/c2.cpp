#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * alice = "Alice\n";
const char * bob = "Bob\n";

int ddp(int p, int q,int j, map<array<int,3>,int> &dp) {
    if(dp.count({p,q,j})) return dp[{p,q,j}];

    if(3*p==2*q) return dp[{p,q,j}] = j;

    if(p>0 and ddp(p-1,q,1-j,dp)==0) return dp[{p,q,j}] = 1;
    if(q>1 and ddp(p,q-1,1-j,dp)==0) return dp[{p,q,j}] = 1;
    return dp[{p,q,j}] = 0;
}

const char * solve() {
    ll p,q;
    cin >> p >> q;

    map<array<int,3>,int> dp;
    dp[{0,1,0}] = 1;
    dp[{0,1,1}] = 0;

    if(ddp(p,q,0,dp)==1) return alice;
    return bob;

}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
