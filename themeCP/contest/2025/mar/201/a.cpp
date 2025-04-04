#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;
    set<int> s;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    int x = *s.begin();
    set<int> s1;
    for(auto i:s) if(i%x) s1.insert(i);
    if(s1.empty()) cout << "YEs\n";
    else {
        x = *s1.begin();
        for(auto i:s1) if(i%x) {
            cout << "no\n";
            return;
        }
        cout << "yeS\n";
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
