#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string a,b;
    cin >> a >> b;
    if(a[0]==b[0]) {
        cout << "YES\n" << a[0] << "*\n";
        return;
    } else if(a.back()==b.back()) {
        cout << "YES\n*" << b.back() << '\n';
        return;
    } else {
        for(ull i=1;i<a.size();i++) for(ull j=1;j<b.size();j++) {
            if(a[i-1]==b[j-1] and a[i]==b[j]) {
                cout << "YES\n*" << a[i-1] << a[i] << "*\n";
                return;
            }
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
