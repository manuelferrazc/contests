#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int no(){ cout << -1 << endl; return 0; }

vector<int> p(110), g(110);
vector<int> comp(110, -1);

void dfs(int v, int k){
    comp[v] = k;
    if(comp[g[v]] == -1) dfs(g[v], k);
}

int main() { _
    int n; cin >> n;
    
    for(int i = 1; i <= n; i++){ int x; cin >> x; g[i] = x, p[x] = i; }

    int k = 0;
    for(int i = 1; i <= n; i++) if(comp[i] == -1){
        dfs(i, k++);
    }

    vector<int> vis(110);
    set<int> st; vector<int> v(110);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i]) vis[v[i]] = 1, st.insert(comp[v[i]]);
    }

    if(st.size() < k) return no();

    for(int i = 0; i < n; i++) if(v[i]){
        for(int j = i-1; j >= 0 and v[j] == 0 and !vis[p[v[j+1]]]; j--) v[j] = p[v[j+1]], vis[v[j]] = 1;
        for(int j = i+1; j < n and v[j] == 0 and !vis[g[v[j-1]]]; j++) v[j] = g[v[j-1]], vis[v[j]] = 1;
    }

    for(int i = 0; i < n; i++) if(!v[i]) return no();

    for(int i = 0; i < n; i++) cout << v[i] << ' ';
    cout << endl;

    return 0;
}