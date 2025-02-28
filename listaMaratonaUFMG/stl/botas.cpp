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

int main() { _
    int n;
    cin >> n;

    vi d(61,0), e(61,0);
    string a;
    int t;

    while(n--) {
        cin >> t >> a;
        if(a[0]=='D') d[t]++;
        else e[t]++;
    }

    int p=0;
    for(int i=0;i<=60;i++) p+=min(d[i],e[i]);

    cout << p << '\n';

    return 0;
}