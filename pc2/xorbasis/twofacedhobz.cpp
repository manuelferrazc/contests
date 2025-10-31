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
    map<int,unsigned> m;

    int getdim() {
        return s.size();
    }

    void add(unsigned mask) {
        for(auto it = s.rbegin();mask and it!=s.rend();it++) {
            mask = min(mask,mask^*it);
        }

        if(mask) {
            auto it = lower_bound(s.begin(), s.end(), mask);
            for(auto it2 = s.rbegin();it2!=s.rend();it2++) {
                if(*it2<mask) break;
                *it2 = min(*it2,mask^*it2);
            }
            
            s.insert(it, mask);
        }
    }

    void buildm() {
        // cout << "base: ";
        for(unsigned i:s) {
            // cout << i << ' ';
            for(int b=30;;b--) {
                if(i&(1<<b)) {
                    m[b]=i;
                    break;
                }
            }
        }
        // cout << "\n, map: ";
        // for(auto [a,b]:m) cout << "{" << a << "->" << b << "}    ";
        // cout << '\n';
    }

    bool contains(ll mask) {
        for(auto it = s.rbegin();mask and it!=s.rend();it++) {
            mask = min(mask,mask^*it);
        }

        if(mask) return false;
        return true;
    }

    unsigned contains2(unsigned mask,int b) {
        unsigned k = mask;
        unsigned ans=0;
        // cout << "c2 com mask = " << k << " e b = " << b << '\n';
        for(int i=30;i>=b;i--) {
            // if(i==3) cout <<"3!!!!!" << ans << '\n';
            if(k&(1<<i)) {
                if(ans&(1<<i)) continue;
                else if(m.count(i)) ans^=m[i];
                else return UINT_MAX;
            } else {
                if(ans&(1<<i)) {
                    if(m.count(i)) ans^=m[i];
                    else return UINT_MAX;
                }
            }
        }

        // cout << ans << ' ' << b << " ... ";


        for(int i=b-1;i>=0;i--) {
            if(k&(1<<i)) {
                if(ans&(1<<i)) continue;
                if(m.count(i)) ans^=m[i];
            } else {
                if(ans&(1<<i)) {
                    if(m.count(i)) ans = ans^m[i];
                }
            }
        }
        // cout << ans << ' ' << b << '\n';
        return ans;
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

unsigned solve(Read &re) {
    unsigned n = re.get();
    unsigned k = re.get();

    unsigned xa = 0;
    base b;

    vector<pair<unsigned,unsigned>> v(n);
    for(unsigned i=0;i<n;i++) {
        v[i].ff = re.get();
        xa^=v[i].ff;

    }

    for(unsigned i=0;i<n;i++) {
        v[i].ss = re.get();
        b.add(v[i].ff^v[i].ss);
    }

    if(b.contains(xa^k)) return k;
    b.buildm();

    for(int i=0;(1<<i)<=k;i++) {
        if((k&(1<<i))==0) continue;

        int tg = (k-(1<<i))|((1<<i)-1);

        int q = b.contains2(xa^tg,i);
        if((q^xa)<=k) return q^xa;
    }

    return 0;
}

int main() { _
    Read r("salkan.in");
    
    int t = r.get();

    while(t--) cout << solve(r) << '\n';

    return 0;
}
