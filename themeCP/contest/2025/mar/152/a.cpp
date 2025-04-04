#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct e {
    int prefix;
    int pos;
    char c;

    e() {}
    
    e(int pr, int po, char cc) {
        prefix = pr;
        pos = po;
        c = cc;
    }

    bool operator<(e o) {
        if(prefix<o.prefix) return true;
        if(prefix>o.prefix) return false;
        return pos>o.pos;
    }
};

int main() { _
    string s;
    cin >> s;

    vector<e> v(s.size());
    int pa=0;
    for(ull i=0;i<s.size();i++) {
        if(s[i]=='(') v[i] = e(pa++,i,'(');
        else v[i] = e(pa--,i,')');
    }

    sort(v.begin(),v.end());
    for(ull i=0;i<v.size();i++) cout << v[i].c;
    cout << '\n';

    return 0;
}
