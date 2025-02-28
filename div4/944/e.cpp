#include <bits/stdc++.h>
#include <limits>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
#define INF INT_MAX
#define LINF LONG_MAX
#define LLINF LONG_LONG_MAX
typedef long long ll;
typedef long l;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef pair<int,int> pii;

int bb(vector<ll> &v, int a, int b, ll dist) {
    if(a==b) return (v[a]<=dist ? a : a-1);

    int m = (a+b)/2;

    if(v[m]<=dist) return bb(v,m+1,b,dist);
    return bb(v,a,m,dist);
}

void solve() {
    ll dest, npts, q;
    ll dist;
    int id;
    cin >> dest >> npts >> q;

    vector<ll> pts(npts+1);
    pts[0] = 0;
    for(ll i=1;i<=npts;i++) cin >> pts[i];

    vector<ll> tempo(npts+1);
    tempo[0] = 0;
    for(ll i=1;i<=npts;i++) cin >> tempo[i];

    while(q--) {
        cin >> dist;

        id = bb(pts,0,npts,dist);
        if(pts[id]==dist) cout << tempo[id] << ' ';
        else {
            ll vard = pts[id+1]-pts[id];
            ll vart = tempo[id+1]-tempo[id];
            ll vardp = dist - pts[id];
            long double vm = (long double)(vard)/(long double)(vart);

            long double temp = vardp/vm;
            cout << tempo[id]+ll(temp+0.00000000001) << ' ';
        }
    }
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}