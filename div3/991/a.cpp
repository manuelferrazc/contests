#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    cin >> n >> m;

    vector<string> s(n);
    for(auto &i:s) cin >> i;
    ull ans = 0;

    for(auto i:s) {
        if(i.size()>m) break;
        else m-=i.size();
        ans++;
    }

    cout << ans << '\n';
}

int main() { _
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
