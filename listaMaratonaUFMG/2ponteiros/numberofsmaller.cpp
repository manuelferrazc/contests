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
    int n,m;
    cin >> n >> m;

    vi v1(n), v2(m);
    for(int i=0;i<n;i++) cin >> v1[i];
    for(int i=0;i<m;i++) cin >> v2[i];

    int i=0,j=0;
    while(i<n and j<m) {
        if(v1[i]<v2[j]) i++;
        else {
            cout << i << ' ';
            j++;
        }
    }

    while(j<m) {
        cout << n << ' ';
        j++;
    }

    cout << '\n';
    return 0;
}
