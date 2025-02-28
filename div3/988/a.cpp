#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,x;
    cin >> n;

    set<int> s;
    int ans = 0;
    while(n--) {
        cin >> x;
        if(s.count(x)) {
            s.erase(x);
            ans++;
        } else s.insert(x);
    }

    cout << ans << endl;
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
