#include <bits/stdc++.h>
#include <climits>

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
    ll n;
    cin >> n;

    ll act = 2;
    ll soma = 3;
    while((n%soma)) {
        act = act<<1;
        soma+=act;
    }

    cout << n/soma << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}