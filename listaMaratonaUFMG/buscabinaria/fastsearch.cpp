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

int bb(vi &v, int a, int b, int x) {
    if(a==b) return v[a]<=x ? a : a-1;

    int m = (a+b)/2;
    if(v[m]<=x) return bb(v,m+1,b,x);
    else return bb(v,a,m,x);
}

int main() { _
    int n;
    cin >> n;
    vi v(n+1);

    for(int i=1;i<=n;i++) cin >> v[i];
    v[0] = INT_MIN;
    sort(v.begin()+1,v.end());

    int q;
    cin >> q;

    while(q--) {
        int a,b;
        cin >> a >> b;

        cout << bb(v,1,n,b) - bb(v,1,n,a-1) << ' ';
    }
    cout << '\n';

    return 0;
}