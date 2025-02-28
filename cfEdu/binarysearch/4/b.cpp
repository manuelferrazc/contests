#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct edge {
    int v;
    double c;

    friend istream& operator>>(istream &in, edge &e) {
        in >> e.v >> e.c;
        e.v--;
        return in;
    }
};

bool check(vector<vector<edge>> &adj, double mean) {
    vector<double> dist(adj.size(),200000);
    dist[0] = 0;

    for(int i=0;i<(int)adj.size();i++) {
        if(dist[i]>10000) continue;

        for(auto e:adj[i]) 
            dist[e.v] = min(dist[e.v],dist[i]+e.c-mean);
    }

    return dist.back()<=1e-8;
}

void find(vector<vector<edge>> &adj, double mean) {
    vector<double> dist(adj.size(),200000);
    vector<int> f(adj.size(),-1);
    dist[0] = 0;

    for(int i=0;i<(int)adj.size();i++) {
        if(dist[i]>10000) continue;

        for(auto e:adj[i]) {
            if(dist[e.v]>dist[i]+e.c-mean) {
                dist[e.v] = dist[i]+e.c-mean;
                f[e.v] = i;
            }
        }
    }

    vector<int> path;
    int i=adj.size()-1;
    while(i!=-1) {
        path.push_back(i+1);
        i=f[i];
    }
    reverse(path.begin(),path.end());
    cout << path.size()-1 << '\n';
    for(auto e:path) cout << e << ' ';
    cout << '\n';
}

int main() { _
    int n,mm;
    cin >> n >> mm;
    vector<vector<edge>> v(n);
    
    for(int i=0;i<mm;i++) {
        int a;
        cin >> a;
        v[a-1].push_back(edge());
        cin >> v[a-1].back();
    }

    double l=0,r=100;

    while(r-l>1e-8) {
        double m = (l+r)/2;
        if(check(v,m)) r=m;
        else l=m;
    }

    find(v,r);

    return 0;
}
