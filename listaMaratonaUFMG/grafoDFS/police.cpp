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
    int n, m, a, b;
    cin >> n >> m;
    vvi v(n+1);

    while(m--) {
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    a = INT_MAX;
    for(int i=1;i<=n;i++) {
        if((int)v[i].size()<a) {
            a = v[i].size();
            b = i;
        }
    }

    vb out(n+1,true);
    out[b] = false;
    for(auto i:v[b]) out[i] = false;

    for(int i=1;i<=n;i++) cout << out[i] << ' ';
    cout << '\n';

    return 0;
}
