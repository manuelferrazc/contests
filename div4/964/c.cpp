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
    int n,s,m;
    cin >> n >> s >> m;

    vector<pii> v(n);

    for(int i=0;i<n;i++) cin >> v[i].f >> v[i].s;

    if(v[0].f>=s) {
        cout << "YES\n";
        return;
    }

    for(int i=1;i<n;i++) {
        if(v[i].f-v[i-1].s>=s) {
            cout << "YES\n";
            return;
        }
    }

    if(m-v.back().s>=s) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}