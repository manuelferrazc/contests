#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct casino {
    int l,r,real;

    casino(){}

    friend istream & operator>>(istream &in,casino &c) {
        in >> c.l >> c.r >> c.real;
        return in;
    }

    bool operator<(casino &o) {
        if(l<o.l) return true;
        if(l>o.l) return false;
        if(r<o.r) return true;
        if(r>o.r) return false;
        return real<o.real;
    }

    void print() {
        cout << "l = " << l << ", r = " << r << ", real = " << real << '\n';
    }
};

void solve() {
    int n,k;
    cin >> n >> k;
    vector<casino> v(n);

    for(casino &i:v) cin >> i;
    sort(v.begin(),v.end());

    set<int> s;
    s.insert(k);

    for(int i=0;i<n;i++) {
        // v[i].print();
        auto it = s.lower_bound(v[i].l);
        if(it!=s.end() and *it<=v[i].r) s.insert(v[i].real);
    }

    cout << *s.rbegin() << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
