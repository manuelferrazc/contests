#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].ff >> v[i].ss;

    pair<int,int> p = v[0];
    for(int i=1;i<n;i++) {
        p.ff = min(p.ff,v[i].ff);
        p.ss = max(p.ss,v[i].ss);
    }

    for(int i=0;i<n;i++) {
        if(v[i]==p) {
            cout << i+1 << '\n';
            return 0;
        };
    }

    cout << "-1\n";

    return 0;
}
