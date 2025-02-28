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

void solve() {
    int n,k;
    cin >> n >> k;

    vector<pii> ret(n);
    for(int i=0;i<n;i++) cin >> ret[i].f >> ret[i].s;

    mii m;
    for(int i=0;i<120;i++) m.insert({i,0});

    for(auto p:ret) {
        int b,a;
        b = max(p.f,p.s);
        a = min(p.f,p.s);

        for(int i=0;i<=a-b;i++) m.at(a)++;
        for(int i=a-b+1;i<b;i++) m.at(b-i)+=2;
    }

    int op=0;
    while(k and m.size()) {
        auto p = m.begin();
        while(k and p->s) {
            k--;
            op+=p->f;
            p->s--;
        }
        m.erase(p);
    }

    if(k==0) cout << op << '\n';
    else cout << "-1\n";
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}