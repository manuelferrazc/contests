#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,k;
    cin >> n >> k;

    int dp[k+1];
    dp[0] = 0;

    int p[n];
    for(int i=0;i<n;i++) cin >> p[i];

    for(int i=1;i<=k;i++) {
        set<int> s;

        for(int j=0;j<n;j++) {
            if(i-p[j]>=0) s.insert(dp[i-p[j]]);
            else break;
        }

        for(int mx=0;;mx++) if(s.count(mx)==0) {
            dp[i] = mx;
            break;
        }
    }

    if(dp[k]) cout << "First\n";
    else cout << "Second\n";

    return 0;
}
