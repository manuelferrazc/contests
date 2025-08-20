#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned ull;

struct base {
    vector<ull> s;

    int getdim() {
        return s.size();
    }

    void add(ull mask) {
        for(auto it = s.rbegin();mask and it!=s.rend();it++) {
            mask = min(mask,mask^*it);
        }

        if(mask) {
            auto it = lower_bound(s.begin(), s.end(), mask);
            s.insert(it, mask);
        }
    }

    bool contains(ull mask) {
        for(auto it = s.rbegin();mask and it!=s.rend();it++) {
            mask = min(mask,mask^*it);
        }

        if(mask) return false;
        return true;
    }

    void operator=(base b) {
        s = b.s;
    }

    void join(base &a, base &b) {
        for(auto it = a.s.begin();it!=a.s.end();it++) add(*it);
        for(auto it = b.s.begin();it!=b.s.end();it++) add(*it);
    }

    void join(base &b) {
        for(auto it = b.s.begin();it!=b.s.end();it++) add(*it);
    }
};

void solve() {
    base b;
    int k,m;
    cin >> k >> m;
    while(m--) {
        ull x;
        cin >> x;
        b.add(x);
    }

    cout << (1ULL<<(k-b.getdim())) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
