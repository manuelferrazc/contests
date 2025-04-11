#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

int main() { _
    int n;
    cin >> n;
    vector<string> v(n);
    for(string &s:v) cin >> s;

    bool ok=false;
    for(int i=0;i<n;i++) {
        if(v[i][0]==v[i][1] and v[i][1]=='O') {
            v[i][0] = v[i][1] = '+';
            ok=true;
            break;
        }
        if(v[i][3]==v[i][4] and v[i][4]=='O') {
            v[i][3] = v[i][4] = '+';
            ok=true;
            break;
        }
    }

    if(ok) {
        cout << "YES\n";
        for(string &s:v) cout << s << '\n';
    } else cout << "NO\n";
    return 0;
}
