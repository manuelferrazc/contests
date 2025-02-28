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
    int n,m;
    cin >> n;
    
    si a;
    for(int i=0;i<n;i++) {
        cin >> m;
        a.insert(m);
    }
    
    cin >> m;
    si b;
    for(int i=0;i<m;i++) {
        cin >> n;
        b.insert(n);
    }

    for(auto i:a) {
        for(auto j:b) {
            if(not (a.count(i+j)!=0 or b.count(i+j))!=0) {
                cout << i << ' ' << j << '\n';
                return 0;
            }
        }
    }


    return 0;
}