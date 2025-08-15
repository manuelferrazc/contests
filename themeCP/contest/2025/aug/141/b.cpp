#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string s;
    cin >> s;

    list<char> ans;

    vector<list<char>::iterator> v,V;

    for(char c:s) {
        if(c>='a' and c<='z') {
            if(c=='b') {
                if(v.size()) {
                    ans.erase(v.back());
                    v.pop_back();
                }
            } else {
                ans.push_back(c);
                v.push_back(prev(ans.end()));
            }
        } else {
            if(c=='B') {
                if(V.size()) {
                    ans.erase(V.back());
                    V.pop_back();
                }
            } else {
                ans.push_back(c);
                V.push_back(prev(ans.end()));
            }
        }
    }


    for(char c:ans) cout << c;
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
