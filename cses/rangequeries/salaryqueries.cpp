#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

int lx = 0;

int main() { _
    int n,q,a,b;
    cin >> n >> q;
    
    ord_set<pair<int,int>> s;
    
    int v[n];
    for(int &i:v) {
        cin >> i;
        s.insert({i,lx++});
    }
    
    string op;
    while(q--) {
        cin >> op >> a >> b;

        if(op[0]=='!') {
            a--;
            s.erase(s.lower_bound({v[a],-1}));
            v[a] = b;
            s.insert({v[a],lx++});
        } else cout << s.order_of_key({b,INT_MAX})-s.order_of_key({a,-1}) << '\n';
    }
    
    return 0;
}
