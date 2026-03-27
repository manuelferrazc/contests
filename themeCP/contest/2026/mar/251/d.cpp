#include <bits/stdc++.h>

// https://codeforces.com/problemset/problem/2107/C

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no() {
    cout << "No\n";
}

void print(ll *v, int n) {
    cout << "Yes\n";
    for(int i=0;i<n;i++) cout << v[i] << ' ';
    cout << '\n';
}

ll get(ll *sp, int a, int b) {
    if(a) return sp[b]-sp[a-1];
    return sp[b];
}

const ll minf = -1'000'000'000'000'000'000ll;

void solve() {
    ll n,k;
    string s;

    cin >> n >> k >> s;

    ll v[n];
    for(int i=0;i<n;i++) cin >> i[v];

    ll sum=0;
    ll mx=0;
    vector<int> z;
    for(ll i=0;i<n;i++) {
        if(s[i]=='0') {
            sum = 0;
            z.push_back(i);
        } else {
            sum+=v[i];
            mx = max(mx,sum);
            if(sum<0) sum = 0;
        }
    }

    if(mx>k) return no();
    if(mx==k) {
        for(auto i:z) v[i] = minf;
        return print(v,n);
    }

    if(z.empty()) return no();

    for(ull i=1;i<z.size();i++) v[z[i]] = minf;

    ll l = 0, r = 0;
    sum = 0;
    for(int i = z[0]-1;i>=0;i--) {
        sum+=v[i];
        l = max(l,sum);
    }

    sum = 0;
    for(int i = z[0]+1;i<n and s[i]=='1';i++) {
        sum+=v[i];
        r = max(r,sum);
    }

    v[z[0]] = k - l - r;

    print(v,n);
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
