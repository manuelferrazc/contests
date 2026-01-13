#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int solve() {
    ll n,k;
    cin >> n >> k;

    int op = 0;
    bool one = false;
    while(n>k) {
        if(n&1) one = true;
        n>>=1;
        if(n==k-1 and one) n++;
        op++;
    }

    if(n==k) return op;
    else return -1;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
