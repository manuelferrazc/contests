#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(not (n&1)) {
        cout << "No\n";
        return 0;
    }

    for(int i=0;i<n/2;i++) if(s[i]!='1') {
        cout << "No\n";
        return 0;
    }
    if(s[n/2]!='/') {
        cout << "No\n";
        return 0;
    }

    for(int i=n/2+1;i<n;i++) if(s[i]!='2') {
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
 
    return 0;
}
