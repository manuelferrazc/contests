#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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
    int x,n,m;
    cin >> x >> n >> m;

    while(x>20 and n--) x = x/2 + 10;
    while(x and m--) x-=10;

    if(x<=0) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
