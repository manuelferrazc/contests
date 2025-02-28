#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,k;
    cin >> n >> k;

    ll d = n-k, a = k-1;
    if((d==0) ^ (a==0)) cout << "-1\n";
    else if (d==0 and a==0) cout << "1\n1\n";
    else if(((d&1)==0) and ((a&1)==0)) {
        d--;
        a--;
        if (d==0 and a==0) cout << "1\n1\n";
        else cout << "3\n" << 1 << ' ' << k-1 << ' ' << k+2 << '\n';
    } else cout << "3\n" << 1 << ' ' << k << ' ' << k+1 << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
