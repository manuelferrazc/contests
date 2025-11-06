#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
	
// para declarar:
// ord_set<int> s;
// coisas do set normal funcionam:
// for (auto i : s) cout << i << endl;
// cout << s.size() << endl;
// k-esimo maior elemento O(log|s|):
// k=0: menor elemento
// cout << *s.find_by_order(k) << endl;
// quantos sao menores do que k O(log|s|):
// cout << s.order_of_key(k) << endl;

// Para fazer um multiset, tem que
// usar ord_set<pair<int, int>> com o
// segundo parametro sendo algo para diferenciar
// os ementos iguais.
// s.order_of_key({k, -INF}) vai retornar o
// numero de elementos < k

int n,k;

ll ans = 0;

vector<int> adj[300000];
ll q[300'000];

ord_set<ll> s;
ll sum;

void dfs(int v) {
    bool ins = false;
    bool ins2 = false;
    ll last;
    if(s.size()==k and *s.begin()<q[v]) {
        ins = true;
        auto it = s.begin();
        
        last = *it;
        
        sum-=*it;
        sum+=q[v];

        s.insert(q[v]);
        s.erase(it);
    } else if(s.size()<k) {
        ins2 = true;
        s.insert(q[v]);
        sum+=q[v];
    }

    if(adj[v].size()==0) ans = max(ans,sum);
    
    for(int u:adj[v]) dfs(u);

    if(ins) {
        sum-=q[v];
        sum+=last;

        s.erase(q[v]);
        s.insert(last);
    } else if(ins2) {
        s.erase(q[v]);
        sum-=q[v];
    }
}

int main() { _
    cin >> n >> k;
    int raiz;

    for(int i=0;i<n;i++) {
        int p;
        cin >> p >> q[i];
        if(p) {
            p--;
            adj[p].push_back(i);
        } else raiz=i;
    }
    
    if(n==1) {
        cout << q[0] << '\n';
        return 0;
    }

    sum = q[raiz];
    s.insert(q[raiz]);

    for(int i:adj[raiz]) dfs(i);

    cout << ans << '\n';

    return 0;
}
