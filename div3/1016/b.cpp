#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string n;
    cin >> n;
    set<int> m;
    for(ull i=0;i<n.size();i++) {
        if(n[i]!='0') m.insert(i); 
    }

    int ans=0;
    int tg = *m.rbegin();
    ans = n.size()-tg-1;
    for(auto i:m) {
        if(i==tg) break;
        else ans++;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
