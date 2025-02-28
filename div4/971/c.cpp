#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

void solve() {
    ll x,y,k;
    cin >> x >> y >> k;

    if(x>y) {
        ll act = 2LL*(y/k + ((y%k)!=0));
        x -= (y%k) ? ((y/k)+1)*k : (y/k)*k;

        if(x<=0) {
            cout << act << '\n';
            return;
        }

        act += 2LL*(x/k);

        act = (x%k)? act+1 : act-1;

        cout << act << '\n';

    } else if(x==y) { // impossivel estar errado
        ll act = 2LL*(x/k);
        if(x%k) act+=2LL;
        cout << act << '\n';
    } else { // impossivel estar errado
        ll act = 2LL*(y/k);
        if(y%k) act+=2LL;
        cout << act << '\n';
    }
}

int main() { _
    int n;
    cin >> n;

    while(n--) solve();

    return 0;
}