#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll solve() {
    int n;
    cin >> n;

    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    for(int i=0;i<n;i++) pq.push({v[i],i});

    vector<bool> vis(n,false);
    ll ans = 0;

    while(not pq.empty()) {
        auto [dist,id] = pq.top();
        pq.pop();
        if(vis[id]) continue;
        vis[id] = true;
        ans = max(ans,dist);

        if(id and not vis[id-1]) pq.push({abs(v[id]-v[id-1]),id-1});
        if(id<n-1 and not vis[id+1]) pq.push({abs(v[id]-v[id+1]),id+1});
    }

    return ans;
}

int main() { _
    int t;
    cin >> t;

    for(int i=1;i<=t;i++) cout << "Case #" << i << ": " << solve() << '\n';
    return 0;
}
