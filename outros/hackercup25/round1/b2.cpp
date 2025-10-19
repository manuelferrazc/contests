#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007;
const int MAX = 100000001;

ll fexp(ll n, ll e) {
    ll r=1,act=n;
    while(e) {
        if(e&1) r=r*act%mod;
        act=act*act%mod;
        e>>=1;
    }
    return r;
}

int *fat;
map<ll,ll> dp;
vector<ll> qtd, m;
ll n,a,b;

void calc2() {
    // qtd = #numero de maneiras de separar os fatores em n
}

void calc(ll act, ull i) {
    if(i==m.size()) return calc2();

    qtd.push_back(0);
    for(int f=0;act<=a and b%act==0;f++) {
        calc(act,i+1);
        qtd.back()++;
        act*=m[i];
    }
}

ll solve() {
    cin >> n >> a >> b;
    
    a = min(a,b);
    
    dp.clear();
    m.clear();
    qtd.clear();

    ll c=b;
    for(int i=2;c>1;i++) {
        while(c%i==0) {
            c/=i;
            if(m.empty() or m.back()!=i) m.push_back(i);
        }
    }



}

int main() { _
    fat = new int[MAX];
    fat[0] = 1;
    for(int i=1;i<MAX;i++) fat[i] = (ll)fat[i-1]*i%mod;

    int t;
    cin >> t;
    for(int i=1;i<=t;i++) cout << "Case #" << i << ": " << solve() << '\n';
    delete[] fat;
    return 0;
}
