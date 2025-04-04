#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<bool> vis;
vector<int> dp;
string s,t;

int dfs(int v,int k,int n) {
    if(vis[v]) return dp[v];
    vis[v] = true;

    for(auto i:{v-k-1,v-k,v+k,v+k+1}) {
        if(i>=0 and i<n) dp[v]|=dfs(i,k,n);
    }


    return dp[v];
}

void solve() {
    int n,k;
    cin >> n >> k >> s >> t;
    vector<int> v(26,0);
    for(auto i:s) v[i-'a']++;
    for(auto i:t) v[i-'a']--;
    for(auto i:v) if(i) {
        cout << "NO\n";
        return ;
    }

    vis.assign(n,false);
    dp.assign(n,0);
    for(int i=0;i<n;i++) dp[i] = 1<<(s[i]-'a');

    int x = dfs(0,k,n);
    bool ok = true;
    for(auto i:vis) if(false==i) {
        ok = false;
        break;
    }
    if(ok) {
        cout << "YES\n";
        return;
    }
    for(int i=0;i<n;i++) 
        if(vis[i]) dp[i] = dp[0];
    
    for(int i=0;i<n;i++){
        if(vis[i] and ((1<<(t[i]-'a'))&x)==0) {
            cout << "NO\n";
            return;
        }
    }

    for(int i=0;i<n;i++) {
        if(vis[i]) continue;
        if(s[i]!=t[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() { 
    int tt;
    cin >> tt;
    while(tt--) solve();
    return 0;
}
