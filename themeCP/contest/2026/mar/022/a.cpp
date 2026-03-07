#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int solve() {
    ll n,k;
    cin >> n >> k;

    if(k==1) return n;

    int ans = 0;

    ll p = 1;
    while(p*k<=n) p*=k;

    while(n) {
        while(p>n) p/=k;
        ans+=n/p;
        n%=p;
    }

    return ans;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
