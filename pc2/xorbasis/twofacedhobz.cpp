#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct base {
    vector<unsigned> s;

    int getdim() {
        return s.size();
    }

    void pivot() {
        for(ll i=s.size()-1;i>0;i--) for(ll j=i-1;j>=0;j--) s[i] = min(s[i],s[i]^s[j]);
    }

    void add(unsigned mask) {
        for(auto it = s.rbegin();mask and it!=s.rend();it++) {
            mask = min(mask,mask^*it);
        }

        if(mask) {
            auto it = lower_bound(s.begin(), s.end(), mask);
            s.insert(it, mask);
            pivot();
        }
    }

    bool contains(ll mask) {
        for(auto it = s.rbegin();mask and it!=s.rend();it++) {
            mask = min(mask,mask^*it);
        }

        if(mask) return false;
        return true;
    }

    unsigned get(ll k) {
        
        ull ans=0;

        for(ull i=0;i<s.size();i++) {
            ull pos = s.size()-i-1;
            if((1ULL<<pos)<k) {
                ans^=s[pos];
                k-=1ULL<<pos;
            }
        }

        return ans;
    }
};

struct Read {
    queue<unsigned> st;

    Read(string &&s) {
        ifstream f(s);
        unsigned x;
        while(f >> x) st.push(x);
        f.close();
    }

    unsigned get() {
        unsigned r = st.front();
        st.pop();
        return r;
    }

    operator bool() {
        return st.size()>0ULL;
    }
};

void solve(Read &r) {
    unsigned n = r.get();
    unsigned k = r.get();

    // unsigned xa = 0;
    base b;
    vector<pair<unsigned,unsigned>> v(n);
    for(unsigned i=0;i<n;i++) {
        v[i].ff = r.get();
        // xa^=v[i].ff;
        cout << "read " << v[i].ff << '\n';

    }

    for(unsigned i=0;i<n;i++) {
        v[i].ss = r.get();
        b.add(v[i].ff^v[i].ss);
        cout << "read " << v[i].ss << '\n';
    }

    // for(auto it = b.s.rbegin();it!=b.s.rend();it++) {
    //     if(xa>k or (xa^*it)>k) xa = min(xa,xa^*it);
    //     else xa = max(xa,xa^*it);
    // }

    cout << "dim: " << n << ' ' << b.getdim() << '\n';

    ll a=1,bb=(1LL<<b.getdim()),ans = 0;

    while(a<=bb) {
        ll m = (a+bb)>>1;

        unsigned g = b.get(m);
        if(g<=k) {
            ans = g;
            a = m+1;
        } else bb = m-1;
    }

    cout << ans << '\n';
    // cout << (xa>k?0:xa) << '\n';
}

int main() { _
    Read r("salkan.in");
    
    int t = r.get();

    while(t--) solve(r);

    // int n;
    // cin >> n;
    // base b;
    // while(n--) {
    //     unsigned x;
    //     cin >> x;
    //     b.add(x);
    // }

    // for(unsigned i:b.s) cout << i << ' ';
    // cout << '\n';


    return 0;
}
