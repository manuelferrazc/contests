#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9+7;
const int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

ll fexp(ll n, ll e) {
    if(e==0) return 1;
    ll r = fexp(n*n%mod,e>>1);
    return e&1 ? r*n%mod : r;
}

ull make_fat(int x) {
    ull r = 0;
    for(int i=0;x>1;i++) {
        while(x%p[i]==0) {
            x/=p[i];
            r^=1ULL<<i;
        }
    }
    return r;
}

struct base {
    set<ull> s;

    int getdim() {
        return s.size();
    }

    void add(int v) {
        ull mask = make_fat(v);

        for(auto it = s.rbegin();mask and it!=s.rend();it++) {
            mask = min(mask,mask^*it);
        }

        if(mask) s.insert(mask);
    }
};

int main() { _
    ll n;
    cin >> n;

    base b;
    for(ll i=0;i<n;i++) {
        int x;
        cin >> x;
        b.add(x);
    }

    cout << (fexp(2,n-b.getdim())-1+mod)%mod << '\n';

    return 0;
}
