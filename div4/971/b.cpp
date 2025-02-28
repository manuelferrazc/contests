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

    vs s(n);
    for(int i=0;i<n;i++) cin >> s[i];

    for(int i=n-1;i>=0;i--) {
        for(int j=0;j<4;j++) if(s[i][j]=='#') {cout << j+1 << ' ';break;}
    }
    cout << '\n';
}

int main() { _
    int n;
    cin >> n;

    while(n--) solve();

    return 0;
}