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

int main() { _
    ll n;
    cin >> n;

    vll v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    sort(v.begin(),v.end());

    ll max = LLONG_MIN;
    ll preco;
    ll anterior = -1;
    for(ll i=0;i<n;i++) {
        if(anterior==v[i]) continue;
        anterior = v[i];
        
        ll lucro = (n-i)*v[i];
        if(lucro>max) {
            max = lucro;
            preco = v[i];
        }
    }

    cout << preco << ' ' << max << '\n';
    

    return 0;
}