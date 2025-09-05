#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

struct Hash {
    ll mod;
    vector<ll> h,p;

    Hash(string &s, ll _m, ll b) : mod(_m), h(s.size()), p(s.size()) {
        p[0] = 1;
        h[0] = s[0];
        for(ull i=1;i<s.size();i++) {
            p[i] = p[i-1]*b%mod;
            h[i] = (h[i-1]*b+s[i])%mod;
        }
    }

    ll get(int l, int r) {
        if(l==0) return h[r];
        return (h[r]-h[l-1]*p[r-l+1]%mod+mod)%mod;
    }
};

int main() { _
    string s;
    cin >> s;
    int n = s.size();

    Hash h1(s,1'000'000'103,uniform(1000,100000)), h2(s,1'000'000'241,uniform(1000,100000));

    for(int i=0;i<n-1;i++) {
        if(h1.get(0,i)==h1.get(n-1-i,n-1) and h2.get(0,i)==h2.get(n-1-i,n-1)) cout << i+1 << ' ';
    }

    cout << '\n';

    return 0;
}
