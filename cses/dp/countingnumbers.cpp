#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll calc(ll n) {
    if(n<10) return n+1;

    vector<int> dn;
    ll n2 = n;
    while(n2) {
        dn.push_back(n2%10);
        n2/=10;
    }

    vector<vector<vector<ll>>> dp(dn.size(),vector<vector<ll>>(10,vector<ll>(2,-1)));

    auto f = [&](auto f2, int x, int d, int eq) -> ll {
        if(dp[x][d][eq]!=-1) return dp[x][d][eq];

        if(x==0) return dp[x][d][eq] = 1;

        dp[x][d][eq] = 0;

        if(eq) {
            for(int nd=0;nd<dn[x-1];nd++) if(nd!=d) dp[x][d][eq]+=f2(f2,x-1,nd,false);
            if(d!=dn[x-1]) dp[x][d][eq]+=f2(f2,x-1,dn[x-1],true);
        } else for(int nd=0;nd<10;nd++) if(nd!=d) dp[x][d][eq]+=f2(f2,x-1,nd,false);

        return dp[x][d][eq];
    };

    ll r=0;
    for(ll d=1;d<dn.back();d++) r+=f(f,dn.size()-1,d,false);

    r+=f(f,dn.size()-1,dn.back(),true);

    for(int p = ((int)dp.size())-2;p>=0;p--) {
        for(int d=1;d<10;d++) r+=f(f,p,d,false);
    }

    return r+1;
}

int main() { 
    ll a,b;
    cin >> a >> b;

    ll b2 = calc(b);
    ll a2=0;
    if(a) a2 = calc(a-1);

    cout << b2-a2 << '\n';
    
    return 0;
}
