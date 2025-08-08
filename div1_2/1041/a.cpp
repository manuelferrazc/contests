#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

auto solve() {
    int n;
    cin >> n;

    set<int> s;
    bool no = false;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        
        if(x>0) s.insert(x);
        if(x==0) no = true;
    }

    if(s.size()>1 or no) return "NO\n";

    return "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
