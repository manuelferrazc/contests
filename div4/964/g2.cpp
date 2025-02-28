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
    if(a>=b) return a;
    int r1 = a + (b-a)/3;
    int r2 = a + ((b-a)*2)/3;

    cout << "? " << r1 << ' ' << r2 << '\n';
    fflush(stdout);
    int q;
    cin >> q;
    if(q==(r2*r1)) return bb(r2+1,b);
    else if(q==(r1*(r2+1))) return bb(r1+1,r2);
    else return bb(a,r1);
}

void solve() {
    int e = bb(1,1000);
    cout << "! " << e << '\n';
}

int main() { 
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}