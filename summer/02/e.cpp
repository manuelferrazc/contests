#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct P {
    int id;
    vector<int> *v;

    P() {
        v = new vector<int>;
    }

    ~P() {
        // delete v;
    }

    bool const operator<(P &o) {
        return v->size()<o.v->size();
    }
};

int p[1'000'000];
vector<int> comp[1'000'000];

int get(int a) {
    return p[a] = (p[a]==a? a : get(p[a]));
}

void unir(int a, int b) {
    a = get(a);
    b = get(b);

    if(a==b) return;
    if(comp[a].size()<comp[b].size()) swap(a,b);
    for(auto u:comp[b]) comp[a].push_back(u);
    comp[b].clear();
    p[b] = a;
}

int main() { _
    int n,m;
    cin >> n >> m;

    vector<P> v(n);

    for(int i=0;i<n;i++) {
        int k;
        cin >> k;

        v[i].id = i;
        while(k--) {
            int x;
            cin >> x;
            x--;
            v[i].v->push_back(x);
        }

        sort(v[i].v->begin(),v[i].v->end());
    }

    sort(v.begin(),v.end());
    int who[m];

    for(int i=0;i<m;i++) {
        p[i] = i;
        comp[i].push_back(i);
    }

    for(int i=0;i<n;i++) {
        if(v[i].v->size()<2ull) continue;

        for(int j=1;j<v[i].v->size();j++) 
            unir(v[i].v->at(j-1),v[i].v->at(j));

        int rep = get(v[i].v->at(0));
        if(comp[rep].size()>v[i].v->size()) {
            int err = -1;
            for(auto j:comp[rep]) {
                auto it = lower_bound(v[i].v->begin(),v[i].v->end(),j);
                if(it==v[i].v->end() or *it!=j) {
                    err = j;
                    break;
                }
            }
            
            cout << "YES\n" << v[i].id+1 << ' ' << v[who[err]].id+1 << '\n';
            for(int i=0;i<n;i++) delete v[i].v;
            return 0;
        }

        for(auto u:*v[i].v) who[u]=i;
    }

    cout << "NO\n";
    for(int i=0;i<n;i++) delete v[i].v;

    return 0;
}
