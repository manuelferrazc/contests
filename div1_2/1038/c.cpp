#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
#define x ff.ff
#define y ff.ss
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<pair<pair<ll,ll>,int>> v(n);
    for(int i=0;i<n;i++) {
        v[i].ss = i;

        cin >> v[i].x >> v[i].y;
    }

    sort(v.begin(),v.end());

    vector<pair<int,int>> ans;

    ll val = 0;
    for(int i=0;ans.size()*2<n;i++) {
        ans.push_back(make_pair(v[i].ss+1,v.back().ss+1));
        val+=abs(v[i].x-v.back().x);
        val+=abs(v[i].y-v.back().y);
        v.pop_back();
    }

    cout << val << '\n';
    for(ull i=0;i<ans.size();i++) cout << ans[i].ff << ' ' << ans[i].ss << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
