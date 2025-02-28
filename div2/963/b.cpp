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
    int n;
    cin >> n;

    multiset<ll> pa;
    set<ll> im;
    
    for(int i=0;i<n;i++) {
        ll c;
        cin >> c;
        if(c&1LL) im.insert(c);
        else pa.insert(c);
    }

    if(im.size()==0 or pa.size()==0) {
        cout << 0 << '\n';
        return;
    }

    ull c=0;

    while(pa.size()) {
        while(*im.rbegin()<=*pa.begin()) {
            c++;
            ll ins = *im.rbegin()+*pa.rbegin();
            im.erase(prev(im.end()));
            im.insert(ins);
        }
        c++;
        ll ins = *im.rbegin()+*pa.begin();
        pa.erase(pa.begin());
        im.insert(ins);
    }

    cout << c << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}