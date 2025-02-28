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

    vi v(n), w(m);
    while(n>0) {cin >> v[n-1];n--;}
    while(m>0) {cin >> w[m-1];m--;}
    while(v.size() and w.size()) {
        if(v.back()<w.back()) {
            cout << v.back() << ' ';
            v.pop_back();
        } else {
            cout << w.back() << ' ';
            w.pop_back();
        }
    }

    while(v.size()) {
        cout << v.back() << ' ';
        v.pop_back();
    }

    while(w.size()) {
        cout << w.back() << ' ';
        w.pop_back();
    }

    cout << '\n';

    return 0;
}
