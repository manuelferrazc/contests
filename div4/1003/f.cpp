#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    string s(n,'0');
    vector<int> v(n);

    for(auto &i:v) {
        cin >> i;
        i--;
    }

    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        if(v[a]==v[b]) s[v[a]] = '1';
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=0;i<n;i++) {
        set<int> set;
        for(auto vv:adj[i]) {
            if(set.count(v[vv])) s[v[vv]] = '1';
            else set.insert(v[vv]); 
        }
    }

    cout << s << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
