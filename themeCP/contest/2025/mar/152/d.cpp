#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int get(vector<int> &p, int a) {
    return p[a] = (a==p[a]?a:get(p,p[a]));
}

void unionG(vector<int> &p, vector<vector<int>> &r, int a, int b) {
    a = get(p,a);
    b = get(p,b);
    if(a==b) return;
    if(r[b].size()>r[a].size()) swap(a,b);
    p[b]=a;
    for(auto i:r[b]) r[a].push_back(i);
    r[b].clear();
}

void unionf(vector<int> &p, vector<int> &r, int a, int b) {
    a = get(p,a);
    b = get(p,b);
    if(a==b) return;
    if(r[b]>r[a]) swap(a,b);
    if(r[a]==r[b]) r[a]++;
    p[b]=a;
}

void solve() {
    int n,mf,mg;
    cin >> n >> mf >> mg;
    
    vector<set<int>> adjg(n), adjf(n);
    vector<int> p(n);
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++) {
        v[i].push_back(i);
        p[i]=i;
    }
    vector<pair<int,int>> sla(mf);
    for(int i=0;i<mf;i++) {
        int a,b;
        cin >> a >> b;
        sla[i] = make_pair(a-1,b-1);
    }

    for(int i=0;i<mg;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        unionG(p,v,a,b);
        adjg[a].insert(b);
        adjg[b].insert(a);
    }

    ll op=0;
    vector<int> pf(n),rf(n,1);
    for(int i=0;i<n;i++) pf[i]=i;

    for(auto i:sla) {
        if(get(p,i.ff)!=get(p,i.ss)) op++;
        else {
            adjf[i.ff].insert(i.ss);
            adjf[i.ss].insert(i.ff);
            unionf(pf,rf,i.ff,i.ss);
        }
    }

    vector<bool> vis(n,false);
    for(int i=0;i<n;i++) {
        if(vis[i]) continue;
        vis[i] = true;
        int a = get(p,i);
        for(auto u:v[a]) {
            vis[u] = true;
            if(get(pf,u)!=get(pf,a)) {
                unionf(pf,rf,get(pf,a),u);
                op++;
            }
        }
    }

    cout << op << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
