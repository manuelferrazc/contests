#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

typedef tree<
pair<int,int>,
null_type,
less<pair<int,int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int lx = 0;

int main() { _
    int n;
    cin >> n;
    vector<pair<pair<int,int>,int>> v(n);
    vector<int> a1(n), a2(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].ff.ff >> v[i].ff.ss;
        v[i].ss = i;
    }

    // sort(v.begin(),v.end());
    sort(v.begin(),v.end(),
    [&](const pair<pair<int,int>,int> &p1,const pair<pair<int,int>,int> &p2) -> bool {
        if(p1.ff.ff<p2.ff.ff) return true;
        if(p1.ff.ff>p2.ff.ff) return false;
        return p1.ff.ss>p2.ff.ss;
    });
    
    ordered_set m;
    
    for(int i=n-1;i>=0;i--) {
        a1[v[i].ss] = m.order_of_key({v[i].ff.ss+1,-10000000});
        m.insert({v[i].ff.ss,lx++});
    }
    
    m.clear();
    lx = 0;

    for(int i=0;i<n;i++) {
        a2[v[i].ss] = m.size()-m.order_of_key({v[i].ff.ss,-1});

        m.insert({v[i].ff.ss,lx++});
    }

    for(int i:a1) cout << i << ' ';
    cout << '\n';
    for(int i:a2) cout << i << ' ';
    cout << '\n';
    
    return 0;
}
