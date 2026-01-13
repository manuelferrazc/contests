#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll s,k,m;
    cin >> s >> k >> m;

    if(s==k) cout << s-m%k << '\n';
    else if(s<k) cout << max(s-m%k,0ll) << '\n';
    else {
        int qtd = m/k;
        if(qtd&1) cout << k-m%k << '\n';
        else cout << s-m%k << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
