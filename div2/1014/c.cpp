#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;

ll dp(vector<ll> &v, vector<vector<vector<ll>>> &ddp, int i, int op,int p) {
    if(i==n) return 0;
    if(ddp[i][p][op]!=-1) return ddp[i][p][op];
    if(p==(v[i]&1)) return ddp[i][p][2] = ddp[i][p][1] = ddp[i][p][0] = max({dp(v,ddp,i+1,0,p),dp(v,ddp,i+1,1,p),dp(v,ddp,i+1,2,p)});

    if(op==0) return ddp[i][p][op] = max({dp(v,ddp,i+1,0,p),dp(v,ddp,i+1,2,p),dp(v,ddp,i+1,1,p)});
    if(op==1) return ddp[i][p][op] = v[i]+max({dp(v,ddp,i+1,0,1),dp(v,ddp,i+1,2,1),dp(v,ddp,i+1,1,1)});
    else return ddp[i][p][op] = v[i]-1+max({dp(v,ddp,i+1,0,0),dp(v,ddp,i+1,2,0),dp(v,ddp,i+1,1,0)});
}

void solve() {
    cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    vector<vector<vector<ll>>> ddp(n,vector<vector<ll>>(2,vector<ll>(3,-1)));
    ll ans=0;
    for(int i=0;i<n;i++) ans=max({ans,v[i]+dp(v,ddp,i+1,0,v[i]&1),v[i]+dp(v,ddp,i+1,1,v[i]&1),v[i]+dp(v,ddp,i+1,2,v[i]&1)});
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
