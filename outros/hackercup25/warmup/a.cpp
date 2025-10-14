#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++) {
        cin >> a[i].ff;
        a[i].ss = i;
    }
    
    for(int i=0;i<n;i++) cin >> b[i];

    map<int,int> m;
    for(int i=0;i<n;i++) m[a[i].ff] = i;

    sort(a.begin(),a.end());
    
    vector<pair<int,int>> ans;

    for(int i=0;i<n;i++) {
        auto [val,id] = a[i];

        if(val==b[id]) continue;
        if(val>b[id]) {
            cout << "-1\n";
            return;
        }
        if(m.count(b[id])) {
            ans.push_back({id+1,m[b[id]]+1});
        } else {
            cout << "-1\n";
            return;
        }
    }

    cout << ans.size() << '\n';
    for(auto [a,b]:ans) cout << a << ' ' << b << '\n';
}

int main() { _
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
