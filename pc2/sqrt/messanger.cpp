#include <bits/stdc++.h>

// Otimizacoes agressivas, pode deixar mais rapido ou mais devagar
#pragma GCC optimize("Ofast")
// Auto explicativo
#pragma GCC optimize("unroll-loops")
// Vetorizacao
#pragma GCC target("avx2")

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


struct Queries {
    queue<tuple<char,int,int>> q;

    void read(int qtd) {
        string s;
        int a,b;
        for(int i=0;i<qtd;i++) {
            cin >> s >> a;
            if(s[0]=='A' or s[0]=='D') cin >> b;

            q.push(tuple(s[0],a,b));
        }
    }

    void get(queue<tuple<char,int,int>> &s, int qtd) {
        while(not s.empty()) s.pop();

        while(qtd>0 and q.size()) {
            s.push(q.front());
            q.pop();
        }
    }

    inline bool end() {
        return q.empty();
    }
};

int main() { _
    int n,m,q,on;
    cin >> n >> m >> q >> on;

    bool online[n];
    for(int i=0;i<n;i++) online[i] = false;
    for(int i=0;i<on;i++) {
        int v;
        cin >> v;
        online[v-1] = true;
    }

    int sq = sqrt(q);
    int sn = sqrt(n);

    unordered_set<int> adj[n];
    unordered_set<int> adjbig[n];

    while(m--) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].insert(b);
        adj[b].insert(a);
    }

    queue<tuple<char,int,int>> st;
    Queries qr;
    qr.read(q);
    bool big[n];
    int qtd[n];

    while(not qr.end()) {
        for(int i=0;i<n;i++) big[i] = (adj[i].size()>=(sn+sq)/2);
        for(int i=0;i<n;i++) {
            adjbig[i].clear();
            for(int j:adj[i]) if(big[j]) adjbig[i].insert(j);
        }

        for(int i=0;i<n;i++) {
            if(not big[i]) continue;
            qtd[i] = 0;
            for(int j:adj[i]) {
                if(online[j]) qtd[i]++;
            }
        }

        qr.get(st,sq);
        while(st.size()) {
            auto [op,a,b] = st.front();
            st.pop();
            a--;
            b--;

            if(op=='O') {
                online[a] = true;
                for(int i:adjbig[a]) qtd[i]++;
            } else if(op=='F') {
                online[a] = false;
                for(int i:adjbig[a]) qtd[i]--;
            } else if(op=='A') {
                adj[b].insert(a);
                adj[a].insert(b);
                
                if(big[a]) {
                    adjbig[b].insert(a);
                    if(online[b]) qtd[a]++;
                }

                if(big[b]) {
                    adjbig[a].insert(b);
                    if(online[a]) qtd[b]++;
                }
            } else if(op=='D') {
                adj[b].erase(a);
                adj[a].erase(b);
                
                if(big[a]) {
                    adjbig[b].erase(a);
                    if(online[b]) qtd[a]--;
                }

                if(big[b]) {
                    adjbig[a].erase(b);
                    if(online[a]) qtd[b]--;
                }
            } else {
                if(not big[a]) {
                    qtd[a]=0;
                    for(int i:adj[a]) if(online[i]) qtd[a]++;
                }
                cout << qtd[a] << '\n';
            }
        }
    }

    return 0;
}
