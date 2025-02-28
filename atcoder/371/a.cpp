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
    string a,b,c;
    cin >> a >> b >> c;

    if(a[0]=='<') {// a é mais novo q b
        if(b[0]=='<') {// a é mais novo q c
            if(c[0]=='<') cout << "B\n";
            else cout << "C\n";
        }
        else cout << "A\n";
    } else { // a é mais velho q b
        if(b[0]=='<') cout << "A\n"; // a é mais novo q c
        else {
            if(c[0]=='<') cout << "C\n";
            else cout << "B\n";
        }
    }
    return 0;
}