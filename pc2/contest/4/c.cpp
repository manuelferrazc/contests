#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char* yes = "YES\n";
const char* no = "NO\n";

const char* solve() {
    int n;
    cin >> n;

    list<int> l;
    vector<list<int>::iterator> v(n);
    vector<bool> del(n,false);

    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        l.push_back(x);
        v[x-1] = prev(l.end());
    }

    if(l.back()==n) return yes;
    else if(l.back()==1 or l.front()==n) return no;

    for(int i=n-1;i;i--) {
        if(del[i]) continue;
        if(v[i]==prev(l.end())) return yes;

        if(v[i]==l.begin()) return no;

        auto p = prev(v[i]);
        auto nx = next(v[i]);

        bool d = false;

        while(true) {
            if(*p<*nx) {
                l.erase(v[i]);
                break;
            } else {
                if(p==l.begin()) {
                    l.erase(v[i]);
                    break;
                }

                del[*p-1] = true;
                l.erase(p);
                p = prev(v[i]);
            }
        }

        // for(int e:l) cout << e << ' ';
        // cout << '\n';
    }

    if((l.size()==2 and *l.begin()<*l.rbegin()) or l.size()==1) return yes;
    else return no;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}