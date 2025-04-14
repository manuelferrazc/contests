#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

int main() { _
    int a,b,c;
    cin >> a >> b >> c;
    
    int m = INT_MAX;
    for(int i=0;i<113;i++) m = min(m,abs(a-i)+abs(b-i)+abs(c-i));
    
    cout << m << '\n';
    return 0;
}
