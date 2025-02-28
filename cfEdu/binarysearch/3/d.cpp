#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define v first
#define num second
typedef long long ll;
typedef unsigned long long ull;

bool bfs(vector<vector<pair<int,int>>> &adj,const int d, const int m) {
    vector<int> dist(adj.size(),INT_MAX);
    dist[0]=0;
    queue<int> q;
    q.push(0);

    while(not q.empty()) {
        int v = q.front();
        q.pop();
        
        for(auto i:adj[v]) {
            if(i.num>m) continue;
            if(dist[i.v]==INT_MAX) {
                dist[i.v]=dist[v]+1;
                q.push(i.v);
            }
        }
    }

    return dist.back()<=d;
}

void find(vector<vector<pair<int,int>>> &adj, const int m, vector<int> &path) {
    vector<pair<int,int>> dist(adj.size(),make_pair(INT_MAX,-1));
    dist[0]=make_pair(0,-1);

    queue<int> q;
    q.push(0);

    while(not q.empty()) {
        int v = q.front();
        q.pop();

        for(auto i:adj[v]) {
            if(i.num>m) continue;
            if(dist[i.v].first==INT_MAX) {
                dist[i.v] = make_pair(dist[v].first+1,v);
                q.push(i.v);
            }
        }
    }

    int x = dist.size()-1;
    while(x!=-1) {
        path.push_back(x);
        x=dist[x].second;
    }
    reverse(path.begin(),path.end());
}

int main() { _
    int n,m,d,l=INT_MAX,r=INT_MIN;
    cin >> n >> m >> d;

    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a-1].push_back(make_pair(b-1,c));
        l=min(l,c);
        r=max(r,c);
    }

    int ans=INT_MAX;

    while(l<=r) {
        int mm = (l+r)>>1;
        if(bfs(adj,d,mm)) {
            ans=min(ans,mm);
            r=mm-1;
        } else l=mm+1;
    }

    if(ans==INT_MAX) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> p;
    find(adj,ans,p);
    cout << p.size()-1 << '\n';
    for(auto i:p) cout << i+1 << ' ';
    cout << '\n';

    return 0;
}
