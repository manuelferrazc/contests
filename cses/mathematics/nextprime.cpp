#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool prime(ll n) {
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(ll i=3;i*i<=n;i+=2) if(n%i==0) return false;
    return true;
}

void solve() {
    ll n;
    cin >> n;
    if(n<3) n++;
    else {
        if(n%2==0) n++;
        else n+=2;
        while(not prime(n)) n++;
    }
    cout << n << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
