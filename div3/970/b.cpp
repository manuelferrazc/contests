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
    string s;
    cin >> s;

    if(s[0] == '0' or s.back()=='0') {
        cout << "No\n";
        return;
    }

    int uns=0;
    for(int i=0;i<n-1;i++) {
        if(s[i+1]=='0') break;
        uns++;
    }
    if(uns == n-1) {
        uns--;
    }
    if(uns*uns!=n) {
        cout << "No\n";
        return;
    }

    int meio = n-uns;
    for(int i=meio;i<n;i++) {
        if(s[i]=='0') {
            cout << "No\n";
            return;
        }
    }

    for(int k=1;k*uns<meio;k++) {
        for(int i=k*uns+1;i<(k+1)*uns-1;i++) {
            if(s[i]=='1') {
                cout << "No\n";
                return;
            }
        }
        if(s[k*uns]=='0' or s[(k+1)*uns-1]=='0') {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
    
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}