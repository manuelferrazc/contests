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

int main() { _
    int n;
    cin >> n;
    vvi v(n+1,vi(n+1));

    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) cin >> v[i][j];

    int act = 1;

    for(int i = 1;i<=n;i++) act = v[max(act,i)][min(act,i)];

    cout << act << '\n';

    return 0;
}