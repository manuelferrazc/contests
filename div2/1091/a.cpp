#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,k;
    cin >> n >> k;

    int s=0;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        s+=x;
    }

    if((s&1) or ((n*k)&1)==0) cout << "YES\n";
    else cout << "No\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
