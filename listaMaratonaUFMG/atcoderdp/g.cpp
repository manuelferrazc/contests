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

vi dist;

void dqt(vvi &adj, int o) {

}

int main() { _
    int n,m;
    cin >> n >> m;

    dist.assign(n+1,INT_MIN);

    vvi adj(n+1);
    vb z(n+1,true);

    int x,y;
    while(m--) {
        cin >> x >> y;
        adj[x].push_back(y);
        z[y] = false;
    }

    return 0;
}
