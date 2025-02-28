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
    ll n,m,k,l;
    cin >> n >> m >> k >> l;

    ll naoTem = n-k;
    if(naoTem<l) cout << "-1\n";
    else {
        l+=k;
        ll x = l/m+(l%m?1:0);
        if(x>(((double)n)/(double)m)) cout << "-1\n"; // nao tem moedas suficientes diferentes
        else cout << x << '\n';
    }

    return 0;
}
