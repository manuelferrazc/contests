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
    ll n,s;
    cin >> n >> s;

    vll v(n);
    for(auto &i:v) cin >> i;

    ll ans = LLONG_MIN,a=0,b=0,sum = v[0];

    while(true) {
        if(sum>=s) { // a soma é maior, tem q diminuir
            if(sum==s) ans = max(ans,b-a+1);
            sum-=v[a];
            a++;
            if(sum<=s) ans = max(ans,b-a+1);
        } else if(b!=n-1) { // a soma é menor, ve se da pra aumentar
            ans = max(ans,b-a+1);
            b++;
            sum+=v[b];
            if(sum<=s) ans = max(ans,b-a+1);
        } else { // teria q aumentar, mas chegou no limite}
            if(sum<=s) ans = max(ans,b-a+1);
            break;
        }
    }


    cout << (ans==LLONG_MIN ? 0 : ans) << '\n';

    return 0;
}
