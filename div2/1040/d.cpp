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

int lx=0;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<pair<int,ord_set<pair<int,int>>>>
        dp0(n,make_pair(-1,ord_set<pair<int,int>>())),
        dp1(n,make_pair(-1,ord_set<pair<int,int>>()));

    dp0[n-1].ff = 0;
    dp0[n-1].ss.insert(make_pair(v[n-1],lx++));
    dp1[n-1].ff = 0;
    dp1[n-1].ss.insert(make_pair(2*n-v[n-1],lx++));

    for(int i=n-2;i>=0;i--) {
        // cout << i    << ' ';
        int n0 = dp0[i+1].ff+dp0[i+1].ss.order_of_key({v[i],-1});
        int n1 = dp1[i+1].ff+dp1[i+1].ss.order_of_key({v[i],-1});

        if(n0<n1) {
            dp0[i].ff = n0;
            dp0[i].ss = dp0[i+1].ss;
            dp0[i].ss.insert({v[i],lx++});
        } else {
            dp0[i].ff = n1;
            dp0[i].ss = dp1[i+1].ss;
            dp0[i].ss.insert({v[i],lx++});
        }

        // cout << n0 << ' ' << n1 << '\n';

        n0 = dp0[i+1].ff+dp0[i+1].ss.order_of_key({2*n-v[i],-1});
        n1 = dp1[i+1].ff+dp1[i+1].ss.order_of_key({2*n-v[i],-1});

        if(n0<n1) {
            dp1[i].ff = n0;
            dp1[i].ss = dp0[i+1].ss;
            dp1[i].ss.insert({2*n-v[i],lx++});
        } else {
            dp1[i].ff = n1;
            dp1[i].ss = dp1[i+1].ss;
            dp1[i].ss.insert({2*n-v[i],lx++});
        }
        // cout << n0 << ' ' << n1 << '\n';

        // cout << dp0[i].ff << ' ' << dp1[i].ff << '\n';

    }

    cout << min(dp0.front().ff,dp1.front().ff) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
