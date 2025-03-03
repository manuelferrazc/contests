#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct lamp {
    int a;
    int b;

    bool operator<(const lamp l) {
        if(a<l.a) return true;
        if(a==l.a) return b>l.b;
        return false;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<lamp> v(n);
    vector<bool> on(n,false);
    for(auto &i:v) cin >> i.a >> i.b;
    sort(v.begin(),v.end());
    int l=0,r=0,q=0;
    ll ans=0;
    while(r<n) {
        ans+=v[r].b;
        on[r] = true;
        r++;
        q++;
        int qtd=q;
        while(l<n and v[l].a<=qtd) {
            if(on[l]) q--;
            l++;
        }
        r=max(r,l);
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
