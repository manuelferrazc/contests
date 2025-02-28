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
    int c=0;
    for(char i: s) if(i=='@') c++;

    n = n - c + d;

    cout << n << '\n';

    return 0;
}
