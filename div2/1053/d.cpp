#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;

int solve() {
    int n;
    cin >> n;

    ll v[n];
    ll s=0;
    for(ll i:v) s+=i;

    if(s!=n or v[n-1]>=2) return 0;

    ll ans = 1, sobra = 0;

    for(int i=n;i>n/2;) {
        i--;

        if(v[i]>1) return 0;

        if(v[i]==0) sobra+=2;
        else {
            ans*=i+sobra;
            ans%=mod;
            if(sobra) sobra-=2;
        }
    }

    for(int i=n/2;;) {
        i--;

        if(v[i]>n-(2*i)+2) return 0;

    }

    return ans;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
