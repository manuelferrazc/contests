#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define x first
#define y second
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

struct ret{
    pll inf,sup;

    ll area(ll l) const {
        if(l<=inf.y) return 0;
        pll aux = make_pair(sup.x-inf.x,min(sup.y,l)-inf.y);
        return aux.x*aux.y;
    }
};

ll sum(vector<ret> &v, ll k) {
    ll sum = 0;
    for(auto &i:v) sum+=i.area(k);
    return sum;
}


int main() { _
    ll n,k;
    cin >> n >> k;

    vector<ret> v(n);
    for(auto &i:v) cin >> i.inf.x >> i.inf.y >> i.sup.x >> i.sup.y;
    
    if(sum(v,INT_MAX)<k) {
        cout << "PERDAO MEU REI\n";
        return 0;
    }

    ll a = INT_MIN,b = INT_MAX;

    while(1) {
        if(a==b) {
            if(sum(v,a)>=k) cout << a << '\n';
            else cout << a+1 << '\n';
            break;
        }

        ll m = (a+b)/2;
        if(sum(v,m)>=k) b = m;
        else a = m+1;
    }

    return 0;
}
