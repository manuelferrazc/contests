#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    bool c=false;
    for(auto i:s) {
        if(i=='x') {
            cout << "No\n";
            return;
        } else if(i=='o') c=true;
    }
    cout << (c? "Yes\n" : "No\n");
}

int main() { _
    solve();
    return 0;
}
