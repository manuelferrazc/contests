#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
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
    string a,b;
    cin >> a >> b;

    for(ull i=0;i<a.size() and i<b.size();i++) {
        if(a[i]!=b[i]) {
            cout << i+1 << endl;
            return 0;
        }
    }
    if(a.size()!=b.size()) cout << min(a.size(),b.size())+1 << endl;
    else cout << 0 << endl;

    return 0;
}
