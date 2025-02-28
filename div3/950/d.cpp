#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg1(a) cout << #a << " = " << a << endl;
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

ll gcd(ll a, ll b) {
    ll aux;
    if(a<b) {
        aux = a;
        a=b;
        b=aux;
    } else if(a==b) return a;

    while(b) {
        aux = a%b;
        a = b;
        b = aux;
    }
    return a;
}

void solve() {
    int n;
    cin >> n;

    vll v(n);

    for(int i=0;i<n;i++) cin >> v[i];

    vll g(n-1);
    bool removeu = false;
    
    for(int i=0;i<n-1;i++) 
        g[i] = gcd(v[i],v[i+1]);
    
    for(int i=0;i<n-1;i++) {
        if(g[i]>g[i+1]) {
            if(removeu) {
                cout << "NO\n";
                return;
            }
            removeu = true;
            ll m = -1;
            if(i) {
                m = gcd(v[i-1],v[i+1]);
                if(m<g[i-1]) m = -1;
            }
            
            if(i>1) {
                if(m==-1) g[i] = gcd(v[i],v[i-2]);
                else g[i] = min(m,g[i]);
            }
        }
    }

    cout << "YES\n";
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}