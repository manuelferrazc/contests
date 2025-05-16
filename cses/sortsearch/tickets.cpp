#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,m,a;
    cin >> n >> m;
    multiset<int> s;

    while(n--) {
        cin >> a;
        s.insert(a);
    }

    while(m--) {
        cin >> a;
        auto it = s.upper_bound(a);
        if(it==s.begin()) cout << -1 << '\n';
        else {
            it--;
            cout << *it << '\n';
            s.erase(it);
        }
    }

    return 0;
}
