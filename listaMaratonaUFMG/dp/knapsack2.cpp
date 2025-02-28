#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define ff first
#define ss second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef set<int> si;

ll n,w,s;

bool testa(vll &p, vll &v, ll val) {
    vector<vll> dp(p.size(),vll(s+1,LLONG_MAX));
    dp[0][0] = 0;

    for(ll i=1;i<=n;i++) {
        for(ll c=0;c<=s;c++) {
            dp[i][c] = dp[i-1][c];

            if(c>=v[i] and dp[i-1][c-v[i]]!=LLONG_MAX) 
                dp[i][c] = min(dp[i][c], dp[i-1][c-v[i]]+p[i]);
        }
    }

    for (ll v = val; v <= s; v++) if(dp[n][v]<=w) return true;
    return false;
}

ll bb(vll &p, vll &v, ll a,ll b) {
    if(a==b) {
        if(testa(p,v,a)) return a;
        return a-1;
    }

    ll m = (a+b)/2;
    if(testa(p,v,m)) return bb(p,v,m+1,b);
    else return bb(p,v,a,m);
}

int main() { _
    cin >> n >> w;
    vll p(n+1),v(n+1);
    for(ll i=1;i<=n;i++) cin >> p[i] >> v[i];
    s = accumulate(v.begin(),v.end(),0);

    cout << bb(p,v,1,s) << '\n';

    return 0;
}
