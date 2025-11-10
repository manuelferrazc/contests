#include <bits/stdc++.h>

#pragma GCC optimize ("O3")

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct Query {
    int l,r,k,i;

    Query(int a, int b, int c, int d): l(a), r(b), i(c), k(d) {}
};

int in[100'000];
int out[100'000];
int label[100'000];
int v[100'000];
int rev[100'000];

int lx=0;

vector<int> adj[100'000];

void dfs(int u, int p=-1) {
    v[lx] = label[u];
    rev[lx] = u;
    in[u] = lx;
    lx++;

    for(int nx:adj[u]) {
        if(nx!=p) dfs(nx,u);
    }

    out[u] = lx-1;
}

struct Queries {
    vector<Query> q;

    void read(int qtd, int sn) {
        int x,k;
        for(int i=0;i<qtd;i++) {
            cin >> x >> k;
            x--;

            q.push_back(Query(in[x],out[x],i,k));
        }

        sort(q.rbegin(),q.rend(),
            [&](const Query &q1, const Query &o) -> bool {
                if(q1.l/sn!=o.l/sn) return q1.l<o.l;
                return q1.r>o.r;
            }
        );
    }

    void get(vector<Query> &s, int mx) {
        s.clear();

        while(q.size() and q.back().l<mx) {
            s.push_back(q.back());
            q.pop_back();
        }

        // sort(s.rbegin(),s.rend(),
        //     [](const Query &q1, const Query &o) -> bool {
        //         return q1.r<o.r;
        //     }
        // );
    }
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;


int main() { _
    int n,q;
    cin >> n;

    for(int i=0;i<n;i++) cin >> label[i];

    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(0);

    cin >> q;
    int ans[q];
    
    int sn = sqrt(n);

    vector<Query> vq;
    Queries qr;
    qr.read(q,sn);

    for(int sq=0;sq*sn<n;) {
        sq++;
        qr.get(vq,sq*sn);
        if(vq.empty()) continue;
        
        int l1 = vq.back().l;
        int r1 = vq.back().r;
        int k1 = vq.back().k;
        int id1 = vq.back().i;
        vq.pop_back();

        ord_set<pair<int,int>> oc;
        for(int i=l1;i<=r1;i++) oc.insert(pair<int,int>(v[i],rev[i]));
        
        int l = l1;
        int r = r1;
        ans[id1] = oc.find_by_order(k1-1)->ss;

        while(vq.size()) {
            int lq = vq.back().l;
            int rq = vq.back().r;
            int k = vq.back().k;
            int id = vq.back().i;
            vq.pop_back();

            while(r<rq) {
                r++;
                oc.insert(pair<int,int>(v[r],rev[r]));
            }

            while(l<lq) {
                oc.erase(oc.lower_bound(pair<int,int>(v[l],rev[l])));
                l++;
            }

            while(lq<l) {
                l--;
                oc.insert(pair<int,int>(v[l],rev[l]));
            }

            ans[id] = oc.find_by_order(k-1)->ss;
        }
    }

    for(int i=0;i<q;i++) cout << i[ans]+1 << '\n';

    return 0;
}
