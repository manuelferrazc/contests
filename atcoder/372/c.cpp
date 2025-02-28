#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define ff first
#define ss second
#define pa (
#define pf )
#define ref &   
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
    int n,q;
    cin >> n >> q;

    string s;
    cin >> s;
    int abc = 0;
    for pa ull i = 0; i<s.size pa pf -2; i++ pf 
        if pa s[i] == 'A' and s[i+1] == 'B' and s[i+2] == 'C' pf abc++;
    
    int x;
    char c;

    while pa q-- pf {
        cin >> x >> c;
        x--;

        
        int a=0,d=0;
        for pa int i = max pa x-2,0 pf;i <=min pa x, n-3 pf;i++ pf
            if pa s[i]=='A' and s[i+1]=='B' and s[i+2]=='C' pf a++;
            
        s[x] = c;
        for pa int i = max pa x-2,0 pf;i <=min pa x, n-3 pf; i++ pf
            if pa s[i]=='A' and s[i+1]=='B' and s[i+2]=='C' pf d++;
            
        abc -= a;
        abc += d;
        cout << abc << endl;
        
    }
    return 0;
}