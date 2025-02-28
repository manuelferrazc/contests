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
    string s,c1,c2;

    cin >> c1 >> c2 >> s;
    for(auto &i:s) 
        if(i-c1[0]) i = c2[0];
    
    cout << s << '\n';

    return 0;
}
