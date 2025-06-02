#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ss first
#define ff second
typedef long long ll;
typedef unsigned long long ull;

struct proj {
    pair<int,int> itv;
    ll p;

    proj() {}
    proj(int a, int b, int c) {
        itv.ss = a;
        itv.ff = b;
        p = c;
    }
    bool operator<(const proj &o) {
        return itv<o.itv;
    }

    friend istream &operator>>(istream &i, proj &o) {
        i >> o.itv.ff >> o.itv.ss >> o.p;
        return i;
    }
};

int main() { _
    int n;
    cin >> n;
    vector<::proj> v(n);
    for(::proj &i:v) cin >> i;
    sort(v.begin(),v.end());

    vector<ll> dp(n);

    for(int i=0;i<n;i++) {
        auto it = lower_bound(v.begin(),v.end(),::proj(v[i].itv.ff,-1,-1));
        if(it==v.begin()) dp[i] = max(v[i].p,i?dp[i-1]:0);
        else {
            it--;
            int id = it-v.begin();
            dp[i] = max(v[i].p+dp[id],dp[i-1]);
        }
    }

    cout << dp.back() << '\n';

    return 0;
}
