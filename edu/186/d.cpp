#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;

ll fat[101];
ll ifat[101];

ll fexp(ll n, ll e) {
    ll r=1;
    
    while(e) {
        if(e&1) r = r*n%mod;
        (n*=n)%=mod;
        e>>=1;
    }
    
    return r;
}

pair<int,int> check(int *v, int n) {
    int l = 1;
    int vz = v[0];
    for(int i=2;i<=n;i++) {
        if(v[i]==v[1]) l++;
        else if(v[i]<v[1]-1) {
            vz -= v[1]-1-v[i];
            if(vz<0) return pair(-1,-1);
        }
    }
    
    if(l+vz>=n) return pair(-2,-2);
    return pair(l,vz);
}

ll solve() {
    int n;
    cin >> n;

    int v[n+1];
    for(int i=0;i<=n;i++) cin >> i[v];
    sort(v+1,v+n+1);
    reverse(v+1,v+n+1);
    
    for(int i=1;i<=n;i++) v[i]-=v[n];

    if(v[1]==0) return fat[n];

    auto [k,s] = check(v,n);
    if(k==-1) return 0;
    else if(k==-2) return fat[n];
    else return ((fat[k+s]*ifat[s])%mod*fat[n-k])%mod;
}

int main() { 
    fat[0] = 1;
    ifat[0] = 1;
    _
    for(int i=1;i<=100;i++) {
        fat[i] = fat[i-1]*i%mod;
        ifat[i] = fexp(fat[i],mod-2);
    }

    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
