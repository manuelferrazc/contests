#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int p = (1<<20)-1;
const ll mod = 1'000'000'007;

ll fexp(ll n, ll e) {
    ll r = 1;
    while(e) {
        if(e&1) r = r*n%mod;
        e>>=1;
        n=n*n%mod;
    }
    return r;
}

int count(int n) {
    int r=0;
    while(n) {
        if(n&1) r++;
        n>>=1;
    }
    return r;
}

int main() { _
    int n;
    cin >> n;
    

    vector<int> oc(p+1,0);
    
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        oc[x]++;
    }

    int *dp = new int[p+1];
    for(int i=0;i<=p;i++) dp[i] = oc[i];
    
    for(int i=0;i<20;i++) {
        for(int x=0;x<=p;x++) {
            if((x&(1<<i))) {
                dp[x^(1<<i)] += dp[x];
            }
        }
    }

    ll ans=0;

    for(int i=0;i<=p;i++) {
        if(count(i)&1) ans = (ans+mod-fexp(2,dp[i]))%mod;
        else ans = (ans+fexp(2,dp[i]))%mod;
    }

    delete[] dp;
    cout << ans << '\n';

    return 0;
}
