#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,q;
    cin >> n >> q;
    set<int> set;
    for(int i=1;i<=n;i++) set.insert(i);

    string s;
    int x;
    while(q--) {
        cin >> s >> x;
        if(s[0]=='-') set.erase(x);
        else {
            auto it = set.lower_bound(x);
            cout << (it==set.end() ? -1 : *it) << '\n';
        }
    }

    return 0;
}
