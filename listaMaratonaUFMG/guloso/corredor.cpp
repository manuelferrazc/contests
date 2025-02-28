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
    int n,x;
    cin >> n;

    int act = 0, max = INT_MIN;

    for(int i=0;i<n;i++) {
        cin >> x;

        act+=x;
        max = ::max(max,act);
        if(act<0) act = 0;
    }

    cout << max << '\n';

    return 0;
}
