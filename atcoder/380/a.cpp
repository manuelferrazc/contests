#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string s;
    cin >> s;
    map<char,int> m;
    for(char i : {'1','2','3'}) m.insert({i,0});

    for(auto c: s) {
        if(not m.count(c)) {
            cout << "No\n";
            return;
        }
        m.at(c)++;
    }

    for(auto p:m) {
        if((p.f-'0')!=p.s) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";    
}

int main() { _
    int t=1;// cin >> t;

    while(t--) solve();

    return 0;
}
