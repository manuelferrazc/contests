#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    set<int> s;
    int x,n;
    cin >> x >> n;
    s.insert(0);
    s.insert(x);
    multiset<int> d;
    d.insert(x);

    while(n--) {
        int p;
        cin >> p;
        auto it = s.upper_bound(p);
        auto it_ant = prev(it);
        int dist = *it-*it_ant;

        d.erase(d.lower_bound(dist));
        d.insert(p-*it_ant);
        d.insert(*it-p);
        s.insert(p);

        cout << *d.rbegin() << '\n';
    }

    return 0;
}
