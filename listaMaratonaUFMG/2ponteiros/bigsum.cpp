#include <bits/stdc++.h>
#include <climits>

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
    ll n,s;
    cin >> n >> s;

    vll v(n);
    for(auto &i:v) cin >> i;

    ll ans = LLONG_MAX,a=0,b=-1,sum = 0;

    while(true) {
        if(sum<s) { // ta pouco, tem q aumentar
            if(b==n-1) break;
            b++;
            sum+=v[b];
        } else { // tem o suficiente, pode diminuir
            ans = min(ans,b-a+1);
            sum-=v[a];
            a++;
        }
    }

    cout << (ans==LLONG_MAX? -1 : ans) << '\n';
    
    return 0;
}
