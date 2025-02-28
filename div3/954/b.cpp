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

bool valido(int x, int y, int n, int m) {
    return (x<n and x>=0 and y<m and y>=0);
}

vector<pii> c = {{1,0},{-1,0},{0,1},{0,-1}};

void solve() {
    int n,m;
    cin >> n >> m;

    vvi v(n,vi(m));

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> v[i][j];

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        int ma = INT_MIN;
        for(pii p : c) {
            if(valido(i+p.f,j+p.s,n,m)) ma = ::max(ma,v[i+p.f][j+p.s]);
        }

        if(ma<v[i][j]) v[i][j] = ma;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cout << v[i][j] << ' ';
        cout << '\n';
    }
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}