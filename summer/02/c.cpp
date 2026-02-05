#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * no = "Impossible\n";

void solve(int n, int m) {
    int g[n];
    for(int i=0;i<n;i++) g[i] = 0;
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        g[a]|=(1<<b);
        g[b]|=(1<<a);
    }

    // int to[1<<n];
    // to[0] = 0;

    // for(int i=1;i<(1<<n);i++) {
    //     int mask = 0;
    //     for(int j=0;j<n;j++) {
    //         if((i&(1<<j))==0) continue;

    //         mask|=g[j];
    //     }
        
    //     to[i] = mask;
    // }

    queue<int> q;
    q.push((1<<n)-1);
    pair<int,int> dist[1<<n];
    for(int i=0;i<(1<<n);i++) dist[i].ff = INT_MAX;
    dist[(1<<n)-1].ff = 0;
    dist[(1<<n)-1].ss = -1;
    int from[1<<n];

    while(not q.empty()) {
        int v = q.front();
        q.pop();

        for(int j=0;j<n;j++) {
            if((v&(1<<j))==0) continue;
            int mask = 0;
            for(int k=0;k<n;k++) {
                if(k!=j and (v&(1<<k))) mask|=g[k];
            }
            if(dist[mask].ff==INT_MAX) {
                dist[mask].ff = dist[v].ff+1;
                dist[mask].ss = j;
                from[mask] = v;

                q.push(mask);
            }
        }
    }

    if(dist[0].ff==INT_MAX) cout << no;
    else {
        cout << dist[0].ff << ':';

        stack<int> s;
        int v = 0;
        while(v!=((1<<n)-1)) {
            s.push(dist[v].ss);
            v = from[v];
        }

        while(s.size()) {
            cout << ' ' << s.top();
            s.pop();
        }
        cout << '\n';
    }
}

int main() { _
    int n,m;
    cin >> n >> m;

    while(n) {
        solve(n,m);
        cin >> n >> m;
    }

    return 0;
}
