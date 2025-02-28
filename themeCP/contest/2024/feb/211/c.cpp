#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,x;
    cin >> n;
    set<int> s;
    for(int i=0;i<n;i++) {
        cin >> x;
        s.insert(x);
    }

    if(s.count(0)) {
        x=1;
        while(s.count(x)) x++;
        cout << x << '\n';
        cout.flush();
        cin >> x;
        while(x>=0) {
            cout << x << '\n';
            cout.flush();
            cin >> x;
        }
        if(x==-1) return;
        else exit(0);
    } else {
        cout << 0 << '\n';
        cout.flush();
        cin >> x;
        if(x==-1) return;
        else if(x==-2) exit(0);
    }
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
