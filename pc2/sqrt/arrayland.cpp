#include <bits/stdc++.h>

// // Otimizacoes agressivas, pode deixar mais rapido ou mais devagar
// #pragma GCC optimize("Ofast")
// // Auto explicativo
// #pragma GCC optimize("unroll-loops")
// // Vetorizacao
// #pragma GCC target("avx2")

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct Query {
    int l,r,i;

    Query(int a, int b, int c): l(a), r(b), i(c) {}
};

struct Queries {
    vector<Query> q;

    void read(int qtd) {
        int a,b;
        for(int i=0;i<qtd;i++) {
            cin >> a >> b;
            a--;
            b--;

            q.push_back(Query(a,b,i));
        }

        sort(q.rbegin(),q.rend(),
            [](const Query &q1, const Query &o) -> bool {
                return q1.l<o.l;
            }
        );
    }

    void get(vector<Query> &s, int mx) {
        s.clear();

        while(q.size() and q.back().l<mx) {
            s.push_back(q.back());
            q.pop_back();
        }

        sort(s.rbegin(),s.rend(),
            [](const Query &q1, const Query &o) -> bool {
                return q1.r<o.r;
            }
        );
    }
};

int main() { _ // se for olhar a submissão, daqui pra baixo tá um código amaldiçoado, a coisa mais intencionalmente feia q eu fiz
    int n,q;
    cin >> n;

    int v[n];
    for(int i=0;i<n;i++) cin >> i[v];
    
    cin >> q;
    int ans[q];
    
    int sn = sqrt(n);

    vector<Query> vq;
    Queries qr;
    qr.read(q);

    for(int sla=0;sla*sn<n;) {
        sla++;
        qr.get(vq,sla*sn);
        
        while(vq.size() and vq.back().r<=(sla*sn)) {
            auto [l,r,id] = vq.back();
            vq.pop_back();

            set<int> oc;
            oc.insert(v[l]);
            int best = INT_MAX;

            for(int i=l+1;i<=r;i++) {
                auto CLUBE_ATLETICO_MINEIRO  = oc.lower_bound(v[i]);
                if(CLUBE_ATLETICO_MINEIRO !=oc.end()) best = min(best,*CLUBE_ATLETICO_MINEIRO -v[i]);
                if(CLUBE_ATLETICO_MINEIRO !=oc.begin()) {
                    CLUBE_ATLETICO_MINEIRO --;
                    best = min(best,v[i]-*CLUBE_ATLETICO_MINEIRO );
                }
                oc.insert(v[i]);
            }
            ans[id] = best;
        }
        
        reverse(vq.begin(),vq.end());
        
        set<int> oc;
        int r = sla*sn;
        int best = INT_MAX;

        for(auto [lq,rq,id]:vq) {
            while(r<rq) {
                r++;
                auto CLUBE_ATLETICO_MINEIRO  = oc.lower_bound(v[r]);
                if(CLUBE_ATLETICO_MINEIRO !=oc.end()) best = min(best,*CLUBE_ATLETICO_MINEIRO -v[r]);
                if(CLUBE_ATLETICO_MINEIRO !=oc.begin()) {
                    CLUBE_ATLETICO_MINEIRO --;
                    best = min(best,v[r]-*CLUBE_ATLETICO_MINEIRO );
                }
                oc.insert(v[r]);
            }

            int best2 = best;

            set<int> i_want_this_set_with_a_large_name_kkkkkkkkkkkkkkkkk_sla;
            for(int i=sla*sn;i>=lq;i--) {
                auto CLUBE_ATLETICO_MINEIRO  = oc.lower_bound(v[i]);
                if(CLUBE_ATLETICO_MINEIRO !=oc.end()) best2 = min(best2,*CLUBE_ATLETICO_MINEIRO -v[i]);
                if(CLUBE_ATLETICO_MINEIRO !=oc.begin()) {
                    CLUBE_ATLETICO_MINEIRO --;
                    best2 = min(best2,v[i]-*CLUBE_ATLETICO_MINEIRO );
                }

                CLUBE_ATLETICO_MINEIRO  = i_want_this_set_with_a_large_name_kkkkkkkkkkkkkkkkk_sla.lower_bound(v[i]);
                if(CLUBE_ATLETICO_MINEIRO !=i_want_this_set_with_a_large_name_kkkkkkkkkkkkkkkkk_sla.end()) best2 = min(best2,*CLUBE_ATLETICO_MINEIRO -v[i]);
                if(CLUBE_ATLETICO_MINEIRO !=i_want_this_set_with_a_large_name_kkkkkkkkkkkkkkkkk_sla.begin()) {
                    CLUBE_ATLETICO_MINEIRO --;
                    best2 = min(best2,v[i]-*CLUBE_ATLETICO_MINEIRO );
                }
                i_want_this_set_with_a_large_name_kkkkkkkkkkkkkkkkk_sla.insert(v[i]);
            }

            ans[id] = best2;
        }
    }

    for(int i=0;i<q;i++) cout << i[ans] << '\n';

    return 0;
}
