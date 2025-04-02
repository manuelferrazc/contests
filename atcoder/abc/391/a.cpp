#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string s;
    cin >> s;

    if(s=="N") cout << "S\n";
    else if(s=="S") cout << "N\n";
    else if(s=="E") cout << "W\n";
    else if(s=="W") cout << "E\n";
    else if(s=="NE") cout << "SW\n";
    else if(s=="SW") cout << "NE\n";
    else if(s=="NW") cout << "SE\n";
    else if(s=="SE") cout << "NW\n";
}

int main() { _
    solve();
    return 0;
}
