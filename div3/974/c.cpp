#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
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
typedef map<int,int> mii;
typedef set<int> si;

void solve() {
    ll n;
    cin >> n;

    vll v(n);
    for(ll i=0;i<n;i++) cin >> v[i];
    if(n==1 or n==2) {
        cout << "-1\n";
        return;
    }

    sort(v.begin(),v.end());
    ll q = v[n/2];
    double m = 0;
    for(auto i:v) m+=i;
    
    ll a=0,b=1e13;
    while(1) {
        if(a==b) {
            if((((m+a-1)/n)/2.0)>q) a--;
            break;
        }

        ll me = (a+b)/2;
        if((((m+me)/n)/2)>q) b = me;
        else a = me+1;
    }
    if(a==-1) a++;
    cout << a << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}