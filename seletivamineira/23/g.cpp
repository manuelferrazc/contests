#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    string a,b;
    cin >> a >> b;
    ll qa=0,qb=0;
    for(char c:a) if(c=='1') qa++;
    for(char c:b) if(c=='1') qb++;

    if(qa>=qb) cout << "YES\n";
    else if((qa&1) and qa+1==qb) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}
