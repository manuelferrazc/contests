#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n, i, mod = 1'000'000'007, ans=0;
    cin >> n;
    for(i=1;i*i<n;i++) {
        if(n%i==0) {
            ans+=i;
            ans+=n/i;
            ans%=mod;
        }
    }

    if(i*i==n) ans = (ans+i*i)%mod;

    cout << ans << '\n';

    return 0;
}
