#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool prime(ll x) {
    if(x<2) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(ll i=2;i*i<=x;i++) if(x%i==0) return false;
    return true;
}

void solve() {

    ll x,k;
    cin >> x >> k;

    if(x==1) {
        ll n=0;
        for(int i=0;i<k;i++) n=n*10+1;
        if(prime(n)) cout <<"YES\n";
        else cout << "NO\n";
    } else if(k>1LL or not prime(x)) cout << "NO\n";
    else cout << "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
