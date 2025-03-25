#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define sobe first
#define lado second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;
ll n,m,d;

vector<string> v;

vector<vector<pair<ll,ll>>> dp;

ll calc(int x,int y);

ll calcs(int x,int y) {
    if(v[x][y]=='#') return 0;
    if(dp[x][y].sobe!=-1) return (dp[x][y].sobe)%mod;
    if(x==n-1) return dp[x][y].sobe=1;
    dp[x][y].sobe = 0;
    for(ll i=0;i<m;i++) {
        if((d*d)-1>((i-x)*(i-x)) and i!=y) dp[x][y].sobe = (dp[x][y].sobe+calc(x+1,i))%mod;
    }
    // cout << x << ' ' << y << ' ' << dp[x][y].sobe << '\n';

    return dp[x][y].sobe%mod;
}

ll calc(int x, int y) {
    if(v[x][y]=='#') return 0;
    if(dp[x][y].sobe!=-1 and dp[x][y].lado!=-1) return (dp[x][y].sobe+dp[x][y].lado)%mod;
    if(x==n-1) {
        if(dp[x][y].sobe==-1) dp[x][y].sobe=1;
        if(dp[x][y].lado==-1) {
            dp[x][y].lado=0;
            for(int i=max(y-d,0LL);i<=min(m-1,y+d);i++) {
                if(i==y) continue;
                if(v[x][i]=='X') dp[x][y].lado++;
            }
        }
        // cout << x << ' ' << y << ' ' << dp[x][y].sobe+dp[x][y].lado << '\n';
        return (dp[x][y].sobe+dp[x][y].lado)%mod;
    }

    // linha de cima
    if(dp[x][y].sobe==-1) {
        dp[x][y].sobe = 0;
        for(int i=max(0LL,y-d+1);i<=min(m-1,y+d-1);i++) {
            auto ababa = (y-i)*(y-i)+1;
            if(d*d>=ababa*ababa) dp[x][y].sobe+=calc(x+1,i);
        }
    }
    if(dp[x][y].lado==-1){
        dp[x][y].lado = 0;
        for(ll i=max(y-d,0LL);i<=min(m-1LL,y+d);i++) if(i!=y) dp[x][y].lado+=calcs(x,i);
    }

    dp[x][y].sobe%=mod;
    dp[x][y].lado%=mod;
    // cout << x << ' ' << y << ' ' << dp[x][y].sobe+dp[x][y].lado << '\n';
    return (dp[x][y].sobe+dp[x][y].lado)%mod;
}

void solve() {
    cin >> n >> m >> d;
    v.resize(n);
    dp.assign(n,vector<pair<ll,ll>>(m,make_pair(-1,-1)));
    for(auto s = v.rbegin();s!=v.rend();s++) cin >> *s;
    
    ll ans=0;
    for(int i=0;i<m;i++) ans=(ans+calc(0,i))%mod;
    cout << ans%mod << '\n';
    // cout << dp[2][1].lado << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
