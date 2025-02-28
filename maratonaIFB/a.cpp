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
    string a;

    while(cin >> a >> a) {
        cin >> a;
        if(a[0]=='S') {
            cout << "facochero\n";
            cin >> a >> a;
        } else if(a[0]=='O') {
            cout << "leao\n";
            for(int i=0;i<4;i++) cin >> a;
        } else {
            cout << "suricato\n";
            cin >> a >> a;
        }
    }

    return 0;
}
