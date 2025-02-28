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

void solve(set<ull> &pr, ull x) {
    if(pr.count(x)) {
        cout << "Prime\n";
        return;
    }

    for(auto i:pr) {
        if((x%i)==0ULL) {
            cout << "Not Prime\n";
            return;
        }
    }

    cout << "Prime\n";
}

int main() { _
    int n;
    cin >> n;

    set<ull> pr;
    vb v(1e5,true);

    for(ull i=2;i<v.size();i++) {
        if(not v[i]) continue;
        pr.insert(i);

        for(ull j=i+i;j<v.size();j+=i) v[j] = false;
    }

    ull x;
    while(n--) {
        cin >> x;
        solve(pr,x);
    }

    return 0;
}