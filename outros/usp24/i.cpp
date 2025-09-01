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
    int n;
    cin >> n;

    int x;
    bool par=false;
    bool imp1 = false;
    bool um = false;

    while(n--) {
        cin >> x;
        if(x==0) continue;
        else if(x==1) um = true;
        else if(x&1) imp1 = true;
        else par = true;
    }

    if(imp1) cout << "2\n";
    else if(um and par) cout << "2\n";
    else if(um or par) cout << "1\n";
    else cout << "0\n";

    return 0;
}