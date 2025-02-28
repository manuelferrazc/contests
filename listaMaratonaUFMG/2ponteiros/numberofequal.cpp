#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef set<int> si;

int main() { _
    ll n,m;
    cin >> n >> m;

    vll a(n),b(m);
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;

    ll ans = 0;
    ll j = 0,i=0;
    while(i<n and j<m) {
        while(a[i]!=b[j] and i<n and j<m) {
            if(a[i] < b[j]) i++;
            else j++;
        }

        if(i==n or j==m) break;

        ll c1=0,c2=0;

        ll x = a[i];
        for(;i<n and a[i]==x;i++) c1++;
        for(;j<m and b[j]==x;j++) c2++;
        ans += c1*c2;
    }

    cout << ans << '\n';

    return 0;
}
