#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n;
    string s,t;
    cin >> n >> s >> t;
    int ans=0;
    for(int i=0;i<n;i++) ans+=s[i]!=t[i];
    cout << ans << '\n';

    return 0;
}
