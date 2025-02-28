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

int dist(int x1,int x2, int x3, int a) {
    return abs(x1-a)+abs(x2-a)+abs(x3-a);
}

void solve() {
    int x1,x2,x3;
    cin >> x1 >> x2 >> x3;
    int m = INT_MAX;
    for(int i=1;i<11;i++) m=min(dist(x1,x2,x3,i),m);

    cout << m << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}