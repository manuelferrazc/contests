#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * yes = "YES\n";
const char * no  = "NO\n";

const char * solve() {
    ll x,y;
    cin >> x >> y;

    if((x+y)%3) return no;
    if(x<2*y) return no;
    if(x<-y*4) return no;
    return yes;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
