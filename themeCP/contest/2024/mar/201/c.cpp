#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

set<ll> s;

void solve() {
    ll n;
    cin >> n;

    if(s.count(n)) cout << "yeS\n";
    else cout << "nO\n";
}

int main() { _
    for(ll k=2;k<=1'000'000LL;k++) {
        ll sum = k+1,p=k;
        while(sum+p*k<=1'000'000LL) {
            p*=k;
            sum+=p;
            s.insert(sum);
        }
    }
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
