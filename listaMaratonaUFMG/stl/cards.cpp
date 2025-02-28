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
    
    string s;
    cin >> s;
    int z=0,u=0;

    for(auto c:s) {
        if(c=='z') z++;
        else if(c=='n') u++;
    }

    while(u--) cout << "1 ";
    while(z--) cout << "0 ";
    cout << '\n';
    
    return 0;
}