#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

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

struct base {
    vector<unsigned> s;

    int getdim() {
        return s.size();
    }

    void add(unsigned mask) {
        for(auto it = s.rbegin();mask and it!=s.rend();it++) {
            mask = min(mask,mask^*it);
        }

        if(mask) {
            auto it = lower_bound(s.begin(), s.end(), mask);
            s.insert(it, mask);
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

unsigned solve(Read &r) {
    unsigned n = r.get();
    unsigned k = r.get();

    unsigned xa = 0;
    base b;

    vector<pair<unsigned,unsigned>> v(n);
    for(unsigned i=0;i<n;i++) {
        v[i].ff = r.get();
        xa^=v[i].ff;

    }

    for(unsigned i=0;i<n;i++) {
        v[i].ss = r.get();
        b.add(v[i].ff^v[i].ss);
    }

    if(b.contains(xa^k)) return k;

    for(int i=0;(1<<i)>=k;i++) {
        unsigned x = k;
        if((xa^k)&(1<<i)) {
            if(x&(1<<i)) x-=(1<<i);
            else x+=(1<<i); 
            x|=(1<<i)-1;
            x-=(1<<i);
        } else continue;
    }

    return 0;
}

int main() { _
    Read r("salkan.in");
    
    int t = r.get();

    while(t--) cout << solve(r) << '\n';

    return 0;
}
