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
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef set<int> si;

int main() { _
    int n, m;
    cin >> n >> m;
    vi v(n);
    for(auto &i:v) cin >> i;

    int a=0, b=0;
    int sum = v.front(), max = 0;

    while(b<n) {
        if(sum<m) {
            max = ::max(sum,max);
            b++;
            if(b<n) sum+=v[b];
        } else {
            sum -= v[a];
            a++;
        }
        if(sum<=m) max = ::max(max,sum);
    }

    cout << max << '\n';

    return 0;
}
