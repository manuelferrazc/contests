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
    multimap<pair<int,int>,pair<int,int>> v;
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        v.insert({{min(a,b),max(a,b)},{a,b}});
    }

    for(auto &i:v) cout << i.ss.ff << ' ' << i.ss.ss << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
