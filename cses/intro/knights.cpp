#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> dp(10001,-1);

ll count(ll n) {
    if(dp[n]!=-1) return dp[n];
    if(n==1) return dp[n] = 0;
    if(n==2) return dp[n] = 6;
    if(n==3) return dp[n] = 28;
    if(n==4) return dp[n] = 96;
    if(n==5) return dp[n] = 252;
    if(n==6) return dp[n] = 550;
    if(n==7) return dp[n] = 1056;

    ll sq = (n-2)*(n-2);
    ll r=4*n-4;
    r = r*(r-1)/2-8;
    r+=12*(sq-2);
    r+=8*(sq-3);
    r+=4*(n-6)*(sq-4);
    r+=count(n-2);
    
    return dp[n] = r;
}

int main() { _
    ll n;
    cin >> n;

    for(ll i=0;i<n;i++) cout << count(i+1) << '\n';
    
    return 0;
}
