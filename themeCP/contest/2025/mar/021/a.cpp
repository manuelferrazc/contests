#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string s,t;
    cin >> s >> t;

    set<char> del;
    ll j = t.size()-1;
    for(ll i=s.size()-1;i>=0;i--) {
        if(s[i]==t[j]) {
            if(del.count(s[i])) {
                cout << "NO\n";
                return;
            }
            j--;
            if(j==-1) {
                cout << "YES\n";
                return;
            }
        } else {
            del.insert(s[i]);
        }
    }

    cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
