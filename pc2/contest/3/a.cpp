#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    string s,t;
    cin >> s >> t;

    set<char> v;
    v.insert('a');
    v.insert('e');
    v.insert('i');
    v.insert('o');
    v.insert('u');

    for(int i=0;i<s.size();i++) {
        if(v.count(s[i])!=v.count(t[i]) or  s.size()!=t.size()) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}
