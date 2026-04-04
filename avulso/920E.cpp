#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int main() { _
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

    for(int i=0;i<n;i++) sort(adj[i].begin(),adj[i].end());
    priority_queue<int> pq;

    bool comp[n];
    fill(comp,comp+n,false);

    int ord[n];
    iota(ord,ord+n,0);
    shuffle(ord,ord+n,rng);

    set<int> f;
    for(int i=0;i<n;i++) f.insert(i);

    for(auto s:ord) {
        if(comp[s]) continue;
        f.erase(s);
        
        queue<int> q;
        q.push(s);
        int size = 0;

        while(q.size()) {
            int v = q.front();
            q.pop();

            comp[v] = true;
            size++;

            for(auto it = f.begin();it!=f.end();) {
                int u = *it;

                auto it2 = lower_bound(adj[v].begin(),adj[v].end(),u);
                if(it2==adj[v].end() or (*it2)!=u) {
                    it++;
                    f.erase(u);
                    
                    q.push(u);
                } else it++;
            }
        }

        pq.push(-size);
    }

    cout << pq.size() << '\n';
    while(pq.size()) {
        cout << -pq.top() << ' ';
        pq.pop();
    }
    
    cout << '\n';

    return 0;
}
