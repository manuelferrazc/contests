#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string s,t;
    cin >> s >> t;
    map<char,int> m1,m2;
    m1.insert({'@',0});
    m2.insert({'@',0});

    for(auto i:s) {
        if(not m1.count(i)) m1.insert({i,0});
        m1.at(i)++;
    }
    for(auto i:t) {
        if(not m2.count(i)) m2.insert({i,0});
        m2.at(i)++;
    }
    set<char> ss = {'a','t','c','o','d','e','r'};
    for(char i:ss) {
        if((not m1.count(i)) and (not m2.count(i))) continue;
        else if(not m1.count(i)) {m1.at('@')-=m2.at(i);continue;}
        else if(not m2.count(i)) {m2.at('@')-=m1.at(i); continue;}

        if(m1.at(i)>m2.at(i)) m2.at('@')-=m1.at(i)-m2.at(i);
        else if(m2.at(i)>m1.at(i)) m1.at('@')-=m2.at(i)-m1.at(i);
    }

    for(char i='b';i<='z';i++) {
        if(ss.count(i)) continue;
        if(m1.count(i) ^ m2.count(i)) {
            cout << "No\n";
            return;
        }

        if(m1.count(i) and m1.at(i)!=m2.at(i)) {
            cout << "No\n";
            return;
        }
    }
    if(m1.at('@')<0 or m2.at('@')<0) cout << "No\n";
    else cout << "Yes\n";
}

int main() { _
    solve();

    return 0;
}
