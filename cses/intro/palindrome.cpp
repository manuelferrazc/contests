#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    string s;
    cin >> s;
    map<char,int> m;
    for(char c:s) m[c]++;

    list<char> l;

    for(auto it = m.begin();it!=m.end();it++) {
        if(it->ss&1) {
            if(l.size()) {
                cout << "NO SOLUTION\n";
                return 0;
            }
            l.push_back(it->ff);
            it->ss--;
        }
    }


    for(auto it = m.begin();it!=m.end();it++) {
        while(it->ss) {
            it->ss-=2;
            l.push_back(it->ff);
            l.push_front(it->ff);
        }
    }

    for(char c:l) cout << c;
    cout << '\n';

    
    return 0;
}
