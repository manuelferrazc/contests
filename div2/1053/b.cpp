#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    string s;
    cin >> n >> m >> s;

    set<int> b,w;
    for(int i=1;i<=2*(n+m);i++) w.insert(i);

    for(int i=0;i<m;i++) {
        int x;
        cin >> x;
        b.insert(x);
        w.erase(x);
    }

    int act=1;
    for(int i=0;i<n;i++) {
        if(s[i]=='A') {
            act++;
            b.insert(act);
        } else {
            int nx = *w.upper_bound(act);
            b.insert(nx);
            w.erase(nx);
            act = *w.upper_bound(act);
        }
        
        // while(*s.begin()<=act) s.erase(s.begin());
    }

    cout << b.size() << '\n';
    for(int i:b) cout << i << ' ';
    cout << '\n';
    cout.flush(); // ????
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
