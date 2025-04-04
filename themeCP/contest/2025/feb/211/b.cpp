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
    multiset<unsigned> s;
    while(n--) {
        cin >> x;
        s.insert(x);
    }
    n=0;
    while(s.size()) {
        auto i = *s.begin();
        while(true) {
            s.erase(s.lower_bound(i));
            if(s.count(i+1)) i++;
            else break;
        }
        n++;
    }
    cout << n << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
