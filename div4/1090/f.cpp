#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no() {
    cout << "NO\n";
}

int s[300'000];

int dfs(vector<int> *adj, int v, int p) {
    s[v] = 1;
    for(int u:adj[v]) {
        if(u!=p) s[v]+=dfs(adj,u,v);
    }

    return s[v];
}

void solve() {
    int x,y;
    cin >> x >> y;

    if(x>y or (x==0 and y%2==0)) return no();
    

    int n = x+y;
    vector<pair<int,int>> adj;

    vector<int> p;
    p.push_back(0);

    for(int i=1;i<n-1;i+=2) {
        adj.push_back(pair(p.back(),i)); // lado
        if(i+2<n) {
            adj.push_back(pair(p.back(),i+1)); // caminho}
            p.push_back(i+1);
        }
    }

    if(n>1) {

        if(n&1) {
            if(x==p.size()) {
                for(auto &[a,b]:adj) {
                    a++;
                    b++;
                }
                adj.push_back(pair(0,1));
            }
            else adj.push_back(pair(p[p.size()-1-x],n-1));
        } else {
            if(x==0) {
                for(auto &[a,b]:adj) {
                    a++;
                    b++;
                }
                adj.push_back(pair(0,1));
            } else adj.push_back(pair(p[x-1],n-1));
        }
    }

    cout << "YES\n";
    for(auto [a,b]:adj) cout << a+1 << ' ' << b+1 << '\n';

    vector<int> g[n];
    for(auto [a,b]:adj) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(g,0,-1);
    
    if(adj.size()!=n-1) exit(1);
    if(s[0]!=n) exit(2);

    if(*min_element(s,s+x+y)!=1) exit(3);
    for(int i=0;i<n;i++) {
        if(s[i]&1) y--;
        else x--;
    }

    if(x) exit(4);
    if(y) exit(5);

}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
