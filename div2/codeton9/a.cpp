#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,id=1;
    cin >> n;

    set<int> us;
    for(int i=1;i<=100 and id<=n;i++) {
        if(us.count(i%id)) continue;
        cout << i << ' ';
        us.insert(i%id);
        id++;
    }

    cout << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
