#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * yes = "YES\n";
const char * no  = "NO\n";

const char * solve() {
    int n;
    cin >> n;

    int v[n+1];
    for(int i=1;i<=n;i++) cin >> i[v];

    for(int i=1;i<=n;i++) {
        if(v[i]==i) continue;
        if(i<n and v[i]==i+1 and v[i+1]==i) swap(v[i],v[i+1]);
        else return no;
    }

    return yes;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
