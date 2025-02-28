#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

void solve() {
    int n,m;
    cin >> n >> m;
    int a,b,c;

    vector<vector<pii>> v(n+1);
    for(int i=0;i<m;i++) {
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }

    cin >> a >> b;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,a});
    vi dist(n+1,INT_MAX);
    vb vi(n+1,false);
    dist[a] = 0;
    while(not pq.empty()) {
        auto p = pq.top();
        pq.pop();

        if(vi[p.s]) continue;
        vi[p.s] = true;

        for(auto e:v[p.s]) {
            if(vi[e.f] or dist[e.f]<=(dist[p.s]+e.s)) continue;
            dist[e.f] = dist[p.s]+e.s;
            pq.push({dist[e.f],e.f});
        }
    }

    if(dist[b]==INT_MAX) cout << "NO\n";
    else cout << dist[b] << '\n';
}

int main() {
    int n;
    cin >> n;

    while(n--) solve();

    return 0;
}