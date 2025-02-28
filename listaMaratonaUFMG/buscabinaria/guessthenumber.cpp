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
typedef map<int,int> mii;
typedef set<int> si;

int main() {
    int l = 1, r = 1'000'000,m;
    string s;

    while(1) {
        if(l==r) {
            cout << l << '\n';
            cin >> s;
            if(s[0]=='>') cout << "! " << l << '\n';
            else cout << "! " << l-1 << '\n';
            break;
        }
        m = (l+r)/2;
        cout << m << '\n';  
        cin >> s;
        if(s[0]=='<') r = m;
        else l = m+1;
    }

    return 0;
}
