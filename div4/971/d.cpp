#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define x first
#define y second
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

    set<pii> s;
    for(int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        s.insert({a,b});
    }

    ll ans = 0;
    for(auto p: s) {
        if(p.y==1) {
            if(s.count({p.x,0})) ans+=(n-2);
        }
        if(s.count({p.x-1,p.y==0}) and s.count({p.x+1,p.y==0})) ans++;
    }
    cout << ans << '\n';
}

int main() { _
    int n;
    cin >> n;

    while(n--) solve();

    return 0;
}