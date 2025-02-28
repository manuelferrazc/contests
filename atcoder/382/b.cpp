#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;

    reverse(s.begin(),s.end());
    for(ull i=0;i<s.size() and d;i++) 
        if(s[i]=='@') {d--; s[i]='.';}

    reverse(s.begin(),s.end());

    cout << s << '\n';

    return 0;
}
