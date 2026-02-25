#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll solve() {
    ll s,m2;
    cin >> s >> m2;

    vector<int> p;
    for(int i=0;i<62;i++) {
        if(m2&(1ll<<i)) p.push_back(i);
    }

    if(s%(1ll<<p.front())) {
        return -1;
    }

    ll n = s/(1ll<<p.front());

    ll l = 1, r = n-1;

    while(l<=r) {
        __int128 m = (l+r)/2;// tamanho da possível resposta
        __int128 sum = 0; // soma do vetor atual
        __int128 rem = s;

        for(int i=p.size()-1;i>=0;i--) {
            sum+=min(rem/(1ll<<p[i])*(1ll<<p[i]),m*(1ll<<p[i]));
            rem = s - sum;
        }

        if(sum==s) {
            n = m;
            r = m-1;
        } else l = m+1;
    }

    return n;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
