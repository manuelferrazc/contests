#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,k,p;
    cin >> n >> k >> p;
    k=abs(k);

    if(n*p<k) cout << "-1\n";
    else cout << k/p + (k%p!=0) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
