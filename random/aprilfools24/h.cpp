#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int t;
    cin >> t;
    string s;
    if(t==1) s="CODEFORCES";
    else if(t==2) s="EYE";
    else if(t==3) s="TESTING";
    else if(t==4) s = "SYSTEM";
    else if(t==5) s = "APRIL";
    else if(t==6) s = "FOOLS";
    else if(t==7) s = "YOU";
    else if(t==8) s = "READ";
    else if(t==9) s = "POORLY";
    else if(t==10) s = "GET";
    else s = "EYEGLASSES";
    cout << s << '\n';
    return 0;
}
