#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<vector<int>> adj;

bool b1,b2;
int a,b;
int dfs(int v, int p=-1) {
    if(v==a and v==b) return 1;
    if(v==a) b1=true;
    if(v==b) b2=true;

    for(int i:adj[v]) {
        if(i==p) continue;
        auto q = dfs(i,v);
        if(q) return q+1;
        if(b1 and b2) return 1;
    }
    return 0;
}

int main() { _
    int n, q;
    cin >> n >> q;
    adj.resize(n);
    for(int i=1;i<n;i++) {
        int a;
        cin >> a;
        a--;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    while(q--) {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        v[0]--;
        v[1]--;
        v[2]--;
        int ans=0;
        for(int i=0;i<3;i++) {
            b1=b2=false;
            a=v[(i+1)%3],b=v[(i+2)%3];
            ans = max(ans,dfs(v[i]));
        }

        cout << ans << '\n';
        
    }
    return 0;
}
