#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

ll s;
ll n;

ll ans = INT_MIN;

void ff(vll &v, ll i, ll act) {
    if(i<n) {
        ff(v,i+1,act);
        ff(v,i+1,act+v[i]);
    } else 
        if(act<=s) ans = max(act,ans);
    
}

int main() { _
    cin >> n;

    vll v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    ll ss = accumulate(v.begin(),v.end(),0LL);
    s = ss/2;
    ff(v,0,0);

    cout << max(ans,ss-ans) << endl;
    
    return 0;
}
