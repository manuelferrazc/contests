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
    vector<int> l(n),dp(n);
    for(int &i:l) {
        cin >> i;
        i--;
    }

    for(int i=0;i<n;i++) {
        dp[i] = 1 + min(i,k) + min(k,n-i-1);
        // cout << dp[i] << ' ' ;
        if(l[i]!=-1) {
            dp[i]+=dp[l[i]];
            if(l[i]+min(k,n-l[i]-1)>=i-min(i,k)) dp[i]-=l[i]+min(k,n-l[i]-1)-(i-min(i,k))+1;
        }
    }
    // cout << "\n";


    for(int i:dp) cout << i << ' ';
    cout << '\n';

    return 0;
}
