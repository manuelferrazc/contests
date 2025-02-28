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

void solve(int a, int v, int t) {
    vi g(a+1,0);

    int p,d;
    while(v--) {
        cin >> p >> d;
        g[p]++;
        g[d]++;
    }

    int m = *max_element(g.begin(),g.end());
    cout << "Teste " << t << '\n';
    for(int i=1;i<=a;i++) if(g[i]==m) cout << i << ' ';
    cout << "\n\n"; 
}

int main() { _
    int a, v, t=1;
    cin >> a >> v;

    while(a) {
        solve(a,v,t++);
        cin >> a >> v;
    }
    return 0;
}
