#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007;

ll get(ll *sp, int a, int b) {
    if(a) return sp[b]-sp[a-1];
    return sp[b];
}

int main() { _
    int n,k;
    cin >> n >> k;

    ll *dp = new ll[k+1];
    dp[0] = 1;
    for(int i=1;i<=k;i++) dp[i] = 0;

    ll *dp2 = new ll[k+1];

    for(int i=0;i<n;i++) {
        ll sp[k+1];
        sp[0] = dp[0];
        for(int j=1;j<=k;j++) sp[j] = sp[j-1]+dp[j];

        int ai;
        cin >> ai;

        for(int qtd = 0;qtd<=k;qtd++) {
            if(qtd<=ai) dp2[qtd] = get(sp,0,qtd)%mod;
            else dp2[qtd] = get(sp,qtd-ai,qtd)%mod;
        }

        swap(dp,dp2);
    }

    cout << dp[k] << '\n';

    delete[] dp;
    delete[] dp2;
    
    return 0;
}
