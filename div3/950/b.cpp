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
    int n,f,k;
    cin >> n >> f >> k;

    vi v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    if(k==n) {
        cout << "YES\n";
        return;
    }

    int fav = v[f-1];

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    if(v[k-1]>fav) cout << "NO\n";
    else if(v[k-1]<fav) cout << "YES\n";
    else {
        if(v[k]==fav) cout << "MAYBE\n";
        else cout << "YES\n";
    }
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}