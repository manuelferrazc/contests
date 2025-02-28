#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

const ll mod = (1e9)+7;

ll fexp(ll a, ll e) {
    if(e==0) return 1;
    if(e==1) return a;
    
    ll ret = fexp(a,e>>1);
    ret = (ret*ret)%mod;
    if(e&1) ret = (ret*a)%mod;

    return ret;
}

void solve(const vll &fat) {
    ll n, k;
    cin >> n >> k;
    ll k2;
    ll u=0,z=0;

    for(int i=0;i<n;i++) {
        cin >> k2;
        if(k2) u++;
        else z++;
    }

    ll ans = 0;

    for(ll q = k;q>=(k/2+1) and (k-q)<=z;q--) {
        if(q>u) continue;
        ans+=((fat[u]*fexp(fat[q],mod-2)%mod*fexp(fat[u-q],mod-2)%mod)*(fat[z]*fexp(fat[k-q],mod-2)%mod*fexp(fat[z-k+q],mod-2)%mod))%mod;
        ans = ans%mod;
    }
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    vector<ll> fat(1e6+1);
    fat[1] = fat[0] = 1;

    for(ll i=2;i<fat.size();i++) fat[i] = (i*fat[i-1])%mod;

    while(t--) solve(fat);

    return 0;
}