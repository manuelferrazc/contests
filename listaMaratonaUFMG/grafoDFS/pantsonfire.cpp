#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define ff first
#define ss second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef set<int> si;

bool dfs(vvi &adj, vb &v, int a, int d) {
    if(a==d) return true;
    v[a] = true;
    for(auto i:adj[a]) if(v[i]==false) if(dfs(adj,v,i,d)) return true;

    return false;
}

int main() { _
    int n,f;
    cin >> n >> f;

    map<string,int> m;
    string a,b;

    vvi adj(193,vi());

    while(n--) {
        cin >> a;
        for(int i=0;i<4;i++) cin >> b;
        if(m.count(a)==0) m.insert({a,m.size()});
        if(m.count(b)==0) m.insert({b,m.size()});
        int ia = m.at(a), ib = m.at(b);

        adj[ia].push_back(ib);
    }

    while(f--) {
        cin >> a;
        for(int i=0;i<4;i++) cin >> b;

        if(m.count(a)==0 or m.count(b)==0) {
            cout << "Pants on Fire\n";
            continue;
        }
        vb v(193,false), v2(193,false);
        if(dfs(adj,v,m.at(a),m.at(b))) cout << "Fact\n";
        else if(dfs(adj,v2,m.at(b),m.at(a))) cout << "Alternative Fact\n";
        else cout << "Pants on Fire\n";
    }

    return 0;
}
