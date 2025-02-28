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

    vll a(n),b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    int m;
    cin >> m;
    map<ll,int> ms;
    // for(int i=0;i<n;i++) if(a[i]!=b[i])

    vll d(m);
    for(int i=0;i<m;i++) {
        cin >> d[i];
    }

    int op=0;
    for(int i=0;i<n;i++) {
        if(a[i]!=b[i]) {
            if(b[i]==d[op]) {
                op++;
            } else {
                op++;
                i--;
            }
            if(op>=m) {
                cout << "NO\n";
                return;
            }
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