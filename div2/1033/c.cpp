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

void solve() {
    ll n,m;
    cin >> n >> m;
    if(m<n or n*(n+1)/2<m) {
        cout << "-1\n";
        return;
    }

    vector<int> v(n);
    ord_set<ll> s;
    for(ll i=1;i<=n;i++) s.insert(i);

    for(int i=0;i<n;i++) {
        auto z = *s.begin();
        ll l=0,r=n-i-1,a = z;
        if(s.size()>1) 
        while(l<=r) {
            int mm = (l+r)>>1;

            auto it = s.find_by_order(mm);
            ll mi = *it + z*(n-i-1);
            if(mi<=m) {
                a=*it;
                l = mm+1;
            } else r=mm-1;
        }

        else v[i] = z;
        
        v[i] = a;
        m-=a;
        s.erase(a);
    }

    cout << v[0] << '\n';
    for(int i=1;i<n;i++) cout << v[i-1] << ' ' << v[i] << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
