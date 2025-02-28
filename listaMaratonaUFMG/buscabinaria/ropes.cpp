#include <bits/stdc++.h>
#include <iomanip>

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
typedef map<int,int> mii;
typedef set<int> si;

ll conta(vi &v,double s) {
    ll r=0;
    for(auto i:v) r+= (i/s);
    return r;
}

double bb(vi &v, double a, double b, ll n) {
    if(fabs(a-b)<0.0000001) return b;
    
    double m = (a+b)/2;

    if(conta(v,m)>=n) return bb(v,m,b,n);
    return bb(v,a,m,n);
}

int main() { _
    ll n,k;
    cin >> n >> k;
    cout << fixed << setprecision(7);

    vi v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    cout << bb(v,0,1e7,k) << '\n';
    return 0;
}