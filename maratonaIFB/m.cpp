#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
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

    vi sp(n);
    sp[0] = v[0];
    for(int i=1;i<n;i++) sp[i] = sp[i-1]+v[i];

    for(int i=0;i<n;i++) {
        if(sp[i-1]==sp.back()-sp[i]) {
            cout << i+1 << '\n';
            return;
        }
    }

    cout << "A cadeira, usa a cadeira!\n";
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
