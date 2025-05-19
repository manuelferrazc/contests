#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    multiset<int> s;
    int n;
    cin >> n;

    while(n--) {
        int x;
        cin >> x;
        auto it = s.upper_bound(x);
        if(it==s.end()) s.insert(x);
        else {
            s.erase(it);
            s.insert(x);
        }
    }

    cout << s.size() << '\n';

    return 0;
}
