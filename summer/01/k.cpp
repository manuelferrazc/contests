#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct monster {
    int a,b,id;
    bool al = true;
};

void solve() {
    int n;
    cin >> n;

    list<monster> l;
    vector<int> ans(n,0);

    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        l.push_back(monster(a,-1,i));
    }

    for(auto it = l.begin();it!=l.end();it++) cin >> it->b;

    for(auto it = l.begin();it!=l.end();it++) {
        int d = 0;
        if(it!=l.begin()) d+=prev(it)->a;
        if(next(it)!=l.end()) d+=next(it)->a;

        if(d>it->b) it->al = false;
    }

    list<list<monster>::iterator> check;
    for(auto it = l.begin();it!=l.end();) {
        if(it->al==false) {
            ans[0]++;
            it = l.erase(it);
            if(it!=l.end() and it->al) check.push_back(it);
        } else {
            if(next(it)!=l.end() and (check.empty() or (*check.back()).id!=it->id) and not next(it)->al) check.push_back(it);
            it++;
        }
    }

    int t = 1;

    while(check.size()) {
        list<list<monster>::iterator> died;
        for(auto it:check) {
            int d = 0;
            if(it!=l.begin()) d+=prev(it)->a;
            if(next(it)!=l.end()) d+=next(it)->a;
            if(d>it->b) {
                it->al = false;
                ans[t]++;
                died.push_back(it);
            }
        }

        t++;
        check.clear();

        for(auto it:died) {
            if(it!=l.begin() and prev(it)->al and (check.empty() or (check.back())->id!=prev(it)->id)) check.push_back(prev(it));
            if(next(it)!=l.end() and next(it)->al) check.push_back(next(it));
        }

        for(auto it:died) l.erase(it);
    }

    for(int i=0;i<n;i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
