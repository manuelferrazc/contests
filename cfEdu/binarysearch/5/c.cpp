#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool check(vector<int> &a, vector<int> &b, int x, ll k) {
    ll r=0;
    for(auto i:a) {
        auto it = lower_bound(b.begin(),b.end(),x-i);
        r+=it-b.begin();
    }
    return r<k;
}

int main() { _
    ll n,k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    unsigned l = 2,r=2'000'000'000, ans=INT_MIN;

    while(l<=r) {
        int m = (l+r)>>1;

        if(check(a,b,m,k)) {
            ans=m;
            l=m+1;
        } else r=m-1;
    }
    
    cout << ans << '\n';

    return 0;
}
