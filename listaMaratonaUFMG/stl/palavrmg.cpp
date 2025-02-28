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
    int p;
    cin >> p;

    while(p--) {
        string s;
        cin >> s;
        string a=s; 
        
        for(ull i=0;i<s.size();i++) a[i] = toupper(a[i]);
        bool b = true;

        for(ull i=0;i<s.size()-1;i++) {
            if(a[i]>=a[i+1]) {
                b=false;
                cout << s << ": N\n";
                break;
            }
        }

        if(b) cout << s << ": O\n";
    }

    return 0;
}