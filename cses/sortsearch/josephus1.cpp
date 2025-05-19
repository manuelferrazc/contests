#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n;
    list<int> l;
    cin >> n;
    for(int i=1;i<=n;i++) l.push_back(i);
    bool j=true;
    while(l.size()) {
        auto it = l.begin();
        if(next(it)==l.end()) {
            cout << *it << ' ';
            break;
        }
        if(j) it++;
        while(true) {
            cout << *it << ' ';
            auto aux = it;
            it++;
            l.erase(aux);
            if(it==l.end()) {
                j = true;
                break;
            }
            it++;
            if(it==l.end()) {
                j = false;
                break;
            }
        }
    }

    cout << '\n';

    return 0;
}
