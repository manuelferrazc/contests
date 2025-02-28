#include <bits/stdc++.h>
#include <string>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
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
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        if(s.size()<=2){
            cout << "NO\n";
            continue;
        }
        if(s[0]=='1' && s[1]=='0') {
            if(s[2]=='0') {
                cout << "NO\n";
                continue;
            }
            string e;
            for(ull i=2;i<s.size();i++) e.push_back(s[i]);
            if(stoi(e)>=2) {
                cout << "YES\n";
                continue;
            }
        }
        cout << "NO\n";
    }

    return 0;
}