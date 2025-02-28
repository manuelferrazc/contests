#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

    set<string> s;
    vs v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    for(int i=n-1;i>=0;i--) {
        if(s.count(v[i])) continue;
        s.insert(v[i]);
        cout << v[i] << '\n';
    }

    return 0;
}
