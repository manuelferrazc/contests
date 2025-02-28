#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define ff first
#define ss second
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
    ll n;
    ull k;
    cin >> n >> k;

    if(k==0LL) {
        cout << "0\n";
        return 0;
    }

    map<ll,ll> m;
    vll v(n);
    for(auto &i:v) cin >> i;

    ll ans = 0,a=0,b=-1;

    while(true) {
        if(m.size()==k and m.count(v[b+1])) {
            b++;
            m.at(v[b])++;
            ans+=b-a+1;
            if(b==n-1) break;
        } else if(m.size()<k) {
            b++;
            if(m.count(v[b])) m.at(v[b])++; 
            else m.insert({v[b],1});
            ans+=(b-a+1);
            if(b==n-1) break;
        } else {
            if(m.at(v[a])==1) m.erase(v[a]);
            else m.at(v[a])--;
            a++;
        }

    }

    cout << ans << '\n';
    return 0;
}
