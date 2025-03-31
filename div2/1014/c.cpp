#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    
    ll im=0,pa=0;
    for(ll &i:v) {
        if(i&1LL) im+=i;
        else pa+=i;
    }

    if(min(im,pa)==0LL) cout << *max_element(v.begin(),v.end()) << '\n';
    else {
        for(ll &i:v) if(i&1) pa+=i-1;
        pa++;
        cout << pa << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
