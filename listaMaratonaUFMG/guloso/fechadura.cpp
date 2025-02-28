#include <bits/stdc++.h>

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

int main() { _
    int n,alv, ans = 0;
    cin >> n >> alv;

    vi v(n+1);
    for(int i=0;i<n;i++) cin >> v[i];

    for(int i=0;i<n;i++) {
        if(v[i]<alv) {
            v[i+1] += alv - v[i];
            ans += alv - v[i];
        } else if(v[i]>alv) {
            v[i+1] -= (v[i] - alv);
            ans += (v[i] - alv);
        }
    }

    cout << ans << '\n';

    return 0;
}
