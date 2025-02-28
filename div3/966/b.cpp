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
    int n;
    cin >> n;

    vi v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    set<int> u;
    u.insert(v[0]);

    for(int i=1;i<n;i++) {
        if(u.count(v[i]+1) or u.count(v[i]-1)) u.insert(v[i]);
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}