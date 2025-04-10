#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n,k;
vector<vector<pair<ll,ll>>> adj;
vector<vector<ll>> dp;

void calc(ll v, ll p) {
    vector<pair<ll,pair<ll,ll>>> l;

    for(auto [u,c]:adj[v]) {
        if(u==p) continue;
        l.push_back({dp[u][0]+c-dp[u][1],{dp[u][1],c}});
    }

    sort(l.rbegin(),l.rend());
    ll i;
    for(i=0;i<min(k,(ll)l.size());i++) { 
        if(l[i].ff<=0) break;
        dp[v][1]+=l[i].ff+l[i].ss.ff;
    }

    for(;i<(ll)l.size();i++) {
        dp[v][1]+=l[i].ss.ff;
    }

    for(i=0;i<min(k-1,(ll)l.size());i++) { 
        if(l[i].ff<=0) break;
        dp[v][0]+=l[i].ff+l[i].ss.ff;
    }

    for(;i<(ll)l.size();i++) {
        dp[v][0]+=l[i].ss.ff;
    }
}

void solve() {
    cin >> n >> k;
    adj.assign(n,{});
    dp.assign(n,vector<ll>(2,0));

    for(ll alan = 1;alan<n;alan++) {
        ll mvkaio,gustavo_cruz,perchuts;
        cin >> mvkaio >> gustavo_cruz >> perchuts;
        mvkaio--;
        gustavo_cruz--;
        adj[mvkaio].push_back({gustavo_cruz,perchuts});
        adj[gustavo_cruz].push_back({mvkaio,perchuts});
    }

    vector<ll> dist(n,LLONG_MAX);
    vector<pair<ll,ll>> vis;
    vis.push_back({0,-1});
    dist[0]=0;
    queue<ll> q;
    q.push(0);
    while(q.size()) {
        ll v = q.front();
        q.pop();

        for(auto [u,sla]:adj[v]) {
            if(dist[u]==LLONG_MAX) {
                dist[u] = dist[v]+1;
                q.push(u);
                vis.push_back({u,v});
            }
        }
    }

    reverse(vis.begin(),vis.end());
    for(auto [v,p]:vis) calc(v,p);
    cout << max(dp[0][0],dp[0][1]) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
