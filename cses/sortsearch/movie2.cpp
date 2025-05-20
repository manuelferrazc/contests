#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ss first
#define ff second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n, k, ans=0;
    cin >> n >> k;
    vector<pair<int,int>> v(n);

    for(auto &i:v) cin >> i.ff >> i.ss;
    sort(v.begin(),v.end());

    multiset<int> s;
    int i;
    for(i=0;i<n and k>(int)s.size();i++) {
        auto it = s.upper_bound(v[i].ff);
        if(it!=s.begin()) {
            ans++;
            it--;
            s.erase(it);
            s.insert(v[i].ss);
            continue;
        }
        ans++;
        s.insert(v[i].ss);
    }

    for(;i<n;i++) {
        auto it = s.upper_bound(v[i].ff);
        if(it!=s.begin()) {
            ans++;
            it--;
            s.erase(it);
            s.insert(v[i].ss);
        }
    }

    cout << ans << '\n';

    return 0;
}
