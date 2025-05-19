#include <bits/stdc++.h>
using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    int n = 1+ rand()%1000;
    cout << n << '\n';
    set<pair<int,int>> s;
    while(true) {
        pair<int,int> p = make_pair(1+rand()%1000,1+rand()%1000);
        if(p.first==p.second) continue;
        if(p.first>p.second) swap(p.first,p.second);
        if(not s.count(p)) {
            cout << p.first << ' ' << p.second << '\n';
            s.insert(p);
            if(s.size()==n) break;
        }
    }
    cout << '\n';
    return 0;
}