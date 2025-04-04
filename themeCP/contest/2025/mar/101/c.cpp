#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

set<int> s;

void solve() {
    int x;
    cin >> x;

    vector<int> ans;
    ans.push_back(x);
    for(int i=0;not s.count(x);i++) {
        if((1<<i)&x) {
            x-=1<<i;
            ans.push_back(x);
        }
    }

    while(x!=1) {
        auto it = prev(s.lower_bound(x));
        x-=*it;
        ans.push_back(x);
    }

    cout << ans.size() << '\n';
    for(auto i:ans) cout << i << ' ';
    cout << '\n';
}

int main() { _
    for(int i=0;i<31;i++) s.insert(1<<i);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
