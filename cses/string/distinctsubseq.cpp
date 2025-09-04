#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007;

// incorrect
int main() { _
    string s;
    cin >> s;
    
    vector<ll> dp(26,0),dn(26,0);

    for(int n = 0;n<s.size();n++) {
        int i = s[n]-'a';
        
        dn = dp;

        if(n and s[n]!=s[n-1]) for(int j=0;j<26;j++) dn[i]+=dp[j];
        else dn[i]*=2;
        if(dp[i]==0) dn[i]++;

        dp = dn;

        cout << "dp: ";
        for(int i:dp) cout << i << ' ';
        cout << '\n';
    }

    cout << accumulate(dp.begin(),dp.end(),0LL)%mod << '\n';
    
    return 0;
}
