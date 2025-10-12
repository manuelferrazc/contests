#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * yes = "YES\n";
const char * no = "NO\n";

bool check(ll n) {
    bool yes  = true,no = false;

    if(n==0) return yes;

    int i = 40;
    while((n&(1LL<<i))==0) i--;

    int j;

    for(j = 0;i>j; j++,i--) {
        if(((n>>i)&1)!=((n>>j)&(1ll))) return no;
    }

    if(j==i and (n&(1ll<<i))) return no;
    else return yes;
}

const char* solve() {
    ll n;
    cin >> n;
    
    if(n==0) return yes;

    int i = 40;
    while((n&(1LL<<i))==0) i--;

    if(check(n)) return yes;
    while(not (n&1)) {
        n>>=1;
        if(check(n)) return yes;
    }

    return no;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
