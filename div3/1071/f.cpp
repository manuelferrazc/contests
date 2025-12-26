#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void first() {
    int n,m;
    cin >> n >> m;

    vector<int> adj[n];
    
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    string ans(n,'0');
    ans[0] = 'r';

    queue<int> q;
    for(int i:adj[0]) {
        q.push(i);
        ans[i] = 'g';
    }

    while(not q.empty()) {
        int v = q.front();
        q.pop();

        char nc;
        if(ans[v]=='r') nc = 'g';
        else if(ans[v]=='g') nc = 'b';
        else nc = 'r';

        for(int u:adj[v]) {
            if(ans[u]=='0') {
                ans[u] = nc;
                q.push(u);
            }
        }
    }

    cout << ans << '\n';
}

void second() {
    int q;
    cin >> q;

    while(q--) {
        int dv;
        cin >> dv;

        string s;
        cin >> s;

        int r=-1,g=-1,b=-1;

        for(int i=0;i<dv;i++) {
            if(s[i]=='r') r=i;
            else if(s[i]=='g') g=i;
            else b=i;
        }

        if(r==-1 and g==-1) cout << b+1 << '\n';
        else if(r==-1 and b==-1) cout << g+1 << '\n';
        else if(g==-1 and b==-1) cout << r+1 << '\n';
        else if(r==-1) cout << b+1 << '\n';
        else if(g==-1) cout << r+1 << '\n';
        else cout << g+1 << '\n';
    }
}

int main() { _
    string s;
    cin >> s;

    auto func = first;

    if(s[0]=='s') func = second;
    
    int t;
    cin >> t;

    while(t--) func();
    
    return 0;
}
