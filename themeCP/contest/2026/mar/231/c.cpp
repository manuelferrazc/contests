#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll x,y,k;
    cin >> x >> y >> k;

    while(k>0 and x>1) {
        ll nx = min(x-(x%y)+y,x+k);
        k -= nx-x;
        while(nx%y==0) nx/=y;
        x = nx;
    }

    k%=(y-1);

    if(k) {
        ll nx = min(x-(x%y)+y,x+k);
        k -= nx - x;
        if(nx%y==0) nx/=y;
        x = nx + k;
    
        if(k) cout << "penis\n";
    }

    cout << x << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
