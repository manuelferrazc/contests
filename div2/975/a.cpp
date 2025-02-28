#include <algorithm>
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

    vi vp,vi;
    for(int i=1;i<=n;i++) {
        int x;
        cin >> x;
        if(i&1) vi.push_back(x);
        else vp.push_back(x);
    }

    if(vp.size() and vi.size()) cout << max(*max_element(vi.begin(),vi.end())+(int)vi.size(),*max_element(vp.begin(),vp.end())+(int)vp.size()) << '\n';
    else if(vp.size()) cout << *max_element(vp.begin(),vp.end())+(int)vp.size() << '\n';
    else cout << *max_element(vi.begin(),vi.end())+(int)vi.size() << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}