#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
#define INF INT_MAX
#define LINF LONG_MAX
#define LLINF LONG_LONG_MAX
typedef long long ll;
typedef long l;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> pii;


int main() { _
    double x, q;
    cin >> x;

    q = sqrt(x+1)+0.1;

    ll n = (x+0.1), r = q;

    if(r*r-1==n and (n%2 and n%3 and n%5)) cout << "S\n";
    else cout << "N\n";
    return 0;
}