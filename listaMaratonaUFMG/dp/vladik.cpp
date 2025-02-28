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

    vi v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    map<int,si> m;
    
    for(int i=0;i<n;i++) {
        if(not m.count(v[i])) m.insert({v[i],si()});
        m.at(v[i]).insert(i);
    }

    return 0;
}