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
    string s;
    cin >> s;

    map<char,int> m;
    for(char c : {'A','B','C','D','?'}) m.insert({c,0});
    for(char c: s) m.at(c)++;

    int r=0;
    for(char c:{'A','B','C','D'}) r+=min(n,m.at(c));

    cout << r << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}