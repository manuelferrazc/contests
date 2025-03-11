#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,a;
    cin >> n;
    multiset<int> s;
    while(n--) {
        cin >> a;
        s.insert(a);
    }

    while(s.size()>1ULL) {
        auto it = s.begin();
        s.insert(*it+*next(it)-1);
        s.erase(s.begin());
        s.erase(s.begin());
    }

    cout << *s.begin() << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
