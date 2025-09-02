#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,k,x=0;
    string s;
    cin >> n >> k >> s;

    map<char,int> m;

    for(int i=0;i+k<=n;) {
        bool ok = true;
        int c=0;
        for(;c<k;c++) {
            if(s[i]!=s[i+c]) {
                ok = false;
                break;
            }
        }
        if(ok) m[s[i]]++;
        i+=c;
    }

    for(auto [a,b]:m) x=max(x,b);
    cout << x << '\n';
    return 0;
}
