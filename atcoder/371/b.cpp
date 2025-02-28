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
    int n, m;
    cin >> n >> m;

    vb j(n+1,false);

    while(m--) {
        int b;
        string s;
        cin >> b >> s;
        if(s[0]=='F') cout << "No\n";
        else {
            if(j[b]) cout << "No\n";
            else {
                j[b] = true;
                cout << "Yes\n";
            }
        }
    }

    return 0;
}