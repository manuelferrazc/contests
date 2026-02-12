#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * alice = "Alice\n";
const char * bob = "Bob\n";



const char * solve() {
    ll p,q;
    cin >> p >> q;

    if(3*p==2*q) return bob;
    if(p>=q) return alice;

    if(3*p-3==2*q-2) return bob;

    ll a = 3*p,b = 2*q; // se a==b (diferente de 0) bob ganha, cc alice ganha
    // qualquer jogador pode subtrair 3 de a ou 2 de b

    if(a<b+2) return alice;
    return bob;

    // ?????????????????
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
