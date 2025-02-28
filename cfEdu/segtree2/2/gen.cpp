#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main(int argc, char  **argv) { _
    srand(atoi(argv[1]));

    ll n = 1+rand()%50000;
    ll m = 1+rand()%10000;
    cout << n << ' ' << m << '\n';

    for(ll i=0;i<m;i++) {
        ll op = 1+(rand()&1);
        ll a = rand()%n;
        ll r = 1+a+rand()%(n-a);
        cout << op << ' ' << a << ' ' << r;
        if(op==1) {
            ll v = rand()%1'000'000'001;
            cout << ' ' << v << '\n';
        } else cout << '\n';
    }

    return 0;
}
