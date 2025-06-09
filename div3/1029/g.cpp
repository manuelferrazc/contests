#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int get(vector<int> &p, int a) {
    return p[a] = (p[a]==a?a:get(p,p[a]));
}

void unionn(vector<int> &p, vector<int> &s, vector<ll> &m, int a, int b,ll w) {
    a = get(p,a);
    b = get(p,b);
    if(a==b) return;

    if(s[a]<s[b]) swap(a,b);
    s[a]+=s[b];
    p[b] = a;
    if(m[a]==0) m[a] = w;
    if(m[b]==0) m[b] = w;
    m[a] = min(m[a],m[b]);
}

struct edge {
    int u,v;
    ll w;

    bool operator<(edge &o) {
        return w<o.w;
    }

    friend istream & operator >> (istream &in, edge &e) {
        in >> e.u >> e.v >> e.w;
        e.u--;
        e.v--;
        return in;
    }
};

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> p(n), s(n,1);
    vector<ll> mi(n,0);
    for(int i=0;i<n;i++) p[i] = i;
    
    vector<edge> edges(m);
    for(auto &i:edges) cin >> i;
    sort(edges.begin(),edges.end());
    
    ll ans = LLONG_MAX;
    for(auto [u,v,w]:edges) {
        int ru = get(p,u),rv = get(p,v);
        if(ru==rv) continue;
        if((get(p,0)==ru and get(p,n-1)==rv) or (get(p,0)==rv and get(p,n-1)==ru)){
            if(mi[ru] and mi[rv]) ans = w + min(mi[ru],mi[rv]);
            else if(mi[ru]) ans = w+mi[ru];
            else if(mi[rv]) ans = w+mi[rv];
            else ans = 2*w;
        } else if((get(p,0)==ru or get(p,n-1)==ru) and ans!=LLONG_MAX) {
            if(mi[ru] and mi[rv]) ans = min(ans,w+min(mi[ru],mi[rv]));
            else if(mi[ru]) ans = min(ans,w+mi[ru]);
            else ans = min(ans,w+mi[rv]);
        } else if((get(p,0)==rv or get(p,n-1)==rv) and ans!=LLONG_MAX) {
            if(mi[ru] and mi[rv]) ans = min(ans,w+min(mi[ru],mi[rv]));
            else if(mi[ru]) ans = min(ans,w+mi[ru]);
            else ans = min(ans,w+mi[rv]);
        }

        unionn(p,s,mi,u,v,w);
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
