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
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    
    cout << max(max(x*b,a*y),max((a-x-1)*b,a*(b-y-1))) << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}