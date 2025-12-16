#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char *yes = "Yes\n";
const char *no = "No\n";

const char * solve() {
    int n;
    cin >> n;

    int v[n],pref[n],suf[n];
    cin >> v[0];
    pref[0] = v[0];
    for(int i=1;i<n;i++) {
        cin >> v[i];
        pref[i] = min(pref[i-1],i[v]);
    }

    suf[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--) suf[i] = max(suf[i+1],i[v]);

    for(int i=1;i<n;i++) {
        if(pref[i-1]>suf[i]) return no;
    }

    return yes;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
