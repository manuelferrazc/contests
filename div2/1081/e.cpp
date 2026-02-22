#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> seq;

int n;
bool dfs(set<pair<int,int>> *adj, int v, int s) {
    int tg = v;

    while(true) {
        // for(int i=0;i<n;i++) {
        //     cout << i << ':';
        //     for(auto [a,b]:adj[i]) cout << ' ' << '(' << a << ',' << b << ')';
        //     cout << '\n';
        // }  
        if(adj[v].empty()) return false;
        auto it = adj[v].begin();
        if(s!=-1) {
            it = adj[v].lower_bound(pair(s,-1));
            s = -1;
        }
        auto [u,i] = *it;
        // cout << "vertices: " << v << ' ' << u << ' ' << ", com id " << i << '\n';

        adj[u].erase(pair(v,i));
        seq.push_back(i);
        if(u!=v) adj[v].erase(*it);

        v = u;

        if(u==tg) return true;
    }
}

void solve() {
    cin >> n;

    int a[n];
    for(int i=0;i<n;i++) cin >> i[a];

    int b[n];
    for(int i=0;i<n;i++) cin >> i[b];

    set<pair<int,int>> adj[n];
    for(int i=0;i<n;i++) {
        a[i]--;
        b[i]--;
        adj[a[i]].insert(pair(b[i],i));
        adj[b[i]].insert(pair(a[i],i));
    }

    bool ok[n];
    vector<int> ans;
    for(int i=0;i<n;i++) ok[i] = false;

    for(int j=0;j<n;j++) {
        if(ok[j]==false) {
            seq.clear();
            if(dfs(adj,a[j],b[j])==false) {
                cout << -1 << '\n';
                return;
            }

            // for(int i:seq) cout << i << ' ';
            // cout << '\n';

            // ans.push_back(seq[0]+1);
            int last = b[seq[0]];
            ok[seq[0]] = true;

            for(ull i=1;i<seq.size();i++) {
                ok[seq[i]] = true;
                if(b[seq[i]]==last) {
                    ans.push_back(seq[i]+1);
                    last = a[seq[i]];
                } else last = b[seq[i]];
            }

        }
    }

    cout << ans.size() << '\n';
    for(int i:ans) cout << i << ' ';
    if(not ans.empty()) cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
