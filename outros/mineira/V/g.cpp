#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
#define int long long

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+31;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

template<int MOD> struct str_hash{
    static int P;
    vector<int> h, p;
    str_hash(string s): h(s.size()), p(s.size()){
        p[0] = 1, h[0] = s[0];
        for(int i = 1; i < s.size(); i++){
            p[i] = p[i-1]*P%MOD, h[i] = (h[i-1]*P+s[i])%MOD;
        }
    }
    int operator()(int l, int r){
        int hash = h[r]-(l ? h[l-1]*p[r-l+1]%MOD : 0);
        return hash < 0 ? hash+MOD : hash;
    }
};

template<int MOD> int str_hash<MOD>::P = uniform(256, MOD-1);

int32_t main() { _
    string s; cin >> s;
    int n = s.size();

    str_hash<MOD> hash(s);
    for(int i = n; i >= 1; i--) if(n%i == 0){
        int sz = n/i; bool can = true;
        for(int j = 0; j < i/2; j++){
            int l = j*sz;
            if(hash(l, l+sz-1) != hash(n-l-sz, n-l-1)){ can = false; break; }
        }

        if(can){ cout << i << endl; break; }
    }

    return 0;
}