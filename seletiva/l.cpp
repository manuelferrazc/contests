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
typedef pair<int,int> pii;


int main() { _
    int x; cin >> x;
    int pares=0,impares=0;

    for(int i=1;i<=x;i++) {
        if(x%i==0) {
            if(i%2) impares++;
            else pares++;
        }
    }

    if(pares==impares) cout << "yes\n";
    else cout << "no\n";
    // bom dimaize
    return 0;
}