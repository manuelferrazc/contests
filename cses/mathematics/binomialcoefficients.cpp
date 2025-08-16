#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9+7;

ll fexp(ll n, ll e=mod-2) {
    if(e==0) return 1;
    ll r = fexp(n*n%mod,e>>1);
    return e&1 ? r*n%mod : r;
}

int main() { _
    vector<ll> fat(1e6+1);
    fat[0] = 1;
    for(int i=1;i<fat.size();i++) fat[i] = fat[i-1]*i%mod;

    int n,a,b;
    cin >> n;

    while(n--) {
        cin >> a >> b;
        cout << fat[a]*fexp(fat[b])%mod*fexp(fat[a-b])%mod << '\n';
    }
    return 0;
}
