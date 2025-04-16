#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string p,s;
    cin >> p >> s;

    vector<int> v1,v2;
    int act=1;
    for(ull i=1;i<p.size();i++) {
        if(p[i]==p[i-1]) act++;
        else {
            v1.push_back(act);
            act=1;
        }
    }
    v1.push_back(act);
    act=1;
    for(ull i=1;i<s.size();i++) {
        if(s[i]==s[i-1]) act++;
        else {
            v2.push_back(act);
            act=1;
        }
    }
    v2.push_back(act);


    if(v1.size()!=v2.size() or s[0]!=p[0]) cout << "NO\n";
    else {
        for(ull i=0;i<v1.size();i++) {
            if(v1[i]>v2[i] or v1[i]*2<v2[i]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
