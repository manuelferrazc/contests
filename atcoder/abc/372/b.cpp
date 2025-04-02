#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define ff first
#define ss second
#define pa (
#define pf )
#define ref &   
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
    int m;
    cin >> m;

    multimap<int,int> out;
    while pa m pf {
        int x = 1,i;
        for pa i = 0; x*3<=m; i++ pf {
            x *=3;
        }
        m-=x;
        out.insert pa {i,x} pf;
    }

    cout << out.size pa pf << endl;
    for pa auto i : out pf cout << i.ff << " ";
    cout << endl;
    return 0;
}