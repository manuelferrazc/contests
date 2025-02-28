#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
#define INF INT_MAX
#define LINF LONG_MAX
#define LLINF LONG_LONG_MAX
typedef long long ll;
typedef long l;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef pair<int,int> pii;

// ull estimay(ull x, ull r)
// {}
ll conta(ll x, ll r, ll r1) {
    ll ret=0;
    
    ll linf = r-x*x;
    ll y = (ll)sqrt(linf);
    if(linf==0) y++;
    if(y*y<linf) y++;

    ll lsup = r1-x*x;

    while(y*y<lsup) {ret++;y++;}

    return ret;
}


void solve() {
    ll r;
    cin >> r;
    ll x=r;
    ll r1 = r+1;
    r1*=r1; // estritamente menor que esse

    r*=r; // maior ou igual a 
    
    ll pts = 0;
    for(;x;x--) {
        pts+=conta(x,r,r1);
    }

    cout << pts*4+4 << '\n';
}

int main() {
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}