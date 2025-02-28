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

int bb(int a, int b) {
    if(a==b) return a;
    int r = (a+b)/2;
    cout << "? " << r << " 1\n";
    fflush(stdout);
    int q;
    cin >> q;

    if(q>r) return bb(a,r);
    else return bb(r+1,b);
}

void solve() {
    int b = bb(1,1000);
    cout << "! " << b << '\n';
}

int main() {
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}