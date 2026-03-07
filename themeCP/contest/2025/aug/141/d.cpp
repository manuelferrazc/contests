#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool dfs(int *adj, bool *vis, int v, int d) {
    if(vis[v]) return d>=26;
    vis[v] = true;

    if(adj[v]!=-1) {
        // cout << v << ' ' << adj[v] << '\n';
        return dfs(adj,vis,adj[v],d+1);
    }

    return true;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    // cout << s << '\n';
    set<char> missing; // faltam mapear
    for(char c='a';c<='z';c++) missing.insert(c);

    bool ap[26];
    fill(ap,ap+26,false);

    map<char,char> m;

    int adj[26];
    fill(adj,adj+26,-1);

    for(int i=0;i<n;i++) {
        if(ap[s[i]-'a']) continue;
        else {
            ap[s[i]-'a'] = true;
            
            for(char c:missing) {
                if(c==s[i]) continue;
                adj[s[i]-'a'] = c-'a';

                bool vis[26];
                fill(vis,vis+26,false);

                if(dfs(adj,vis,s[i]-'a',0)) {
                    missing.erase(c);
                    m[s[i]] = c;
                    break;
                }
            }
            // exit(0);
        }
    }

    for(char c:s) cout << m[c];
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
