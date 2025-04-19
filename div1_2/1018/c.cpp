#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n;
vector<ll> vl,vc;

pair<ll,ll> ll1(vector<vector<ll>> &v, ll i) {
    pair<ll,ll> r={0,0};
    for(ll j=0;j<n;j++) {
        if(v[i][j]==v[i+1][j]+1) r.ff = 1;
        else if(v[i][j]==v[i+1][j]-1) r.ss = 1;
    }
    return r;
}

ll calcl(vector<vector<ll>> &v, vector<vector<ll>> &r) {
    vector<pair<ll,ll>> custo,dp(r.size());
    for(auto &sla:r) {
        custo.push_back({0,0});
        for(ull i=0;i<sla.size();i++) {
            if(i&1) custo.back().ff+=vl[sla[i]];
            else custo.back().ss+=vl[sla[i]];
        }
    }

    dp[0] = custo[0];
    for(ull i=1;i<r.size();i++) {
        
    }
}

void solve() {
    cin >> n;
    vector<vector<ll>> v(n,vector<ll>(n));
    for(ll i=0;i<n;i++) for(ll &j:v[i]) cin >> j;
    vl.resize(n);
    for(ll &i:vl) cin >> i;
    vc.resize(n);
    for(ll &i:vc) cin >> i;

    vector<vector<ll>> row,col;
    for(ll i=0;i<n-1;i++) {
        ll b=-1;
        for(ll j=0;j<n;j++) {
            if(v[i][j]==v[i+1][j]) {
                b=i;
                break;
            }
        }
        if(b!=-1) {
            row.push_back({i});
            for(ll l=i+1;l<n;l++) {
                bool er=false;
                for(ll j=0;j<n;j++) {
                    if(v[l][j]==v[l-1][j]) {
                        er=true;
                        row.back().push_back(l);
                        break;
                    }
                }
                if(er) continue;
            }
            i=row.back().back();
        }
    }

    for(ll j=0;j<n-1;j++) {
        ll b=-1;
        for(ll i=0;i<n;i++) {
            if(v[i][j]==v[i][j+1]) {
                b=j;
                break;
            }
        }
        if(b!=-1) {
            col.push_back({j});
            for(ll l=j+1;l<n;l++) {
                bool er=false;
                for(ll i=0;i<n;i++) {
                    if(v[i][l]==v[i][l-1]) {
                        er=true;
                        col.back().push_back(l);
                        break;
                    }
                }
                if(er) continue;
            }
            j=col.back().back();
        }
    }
    cout << row.size() << ' ' << col.size() << '\n';
    // ll ans=LLONG_MAX;
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
