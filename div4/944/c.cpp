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
typedef pair<int,int> pii;


int main() { _
    int n; cin >> n;
    
    while(n--) {
        int a1, a2, b1,b2;
        cin >> a1 >> a2 >> b1 >> b2;
        if(a2<a1) {
            int aux = a1;
            a1 = a2;
            a2 = aux;
        }
        if(b2<b1) {
            int aux = b1;
            b1=b2;
            b2=aux;
        }

        if(b1<a1) {
            if(b2>a1 and b2 <a2) cout << "YES\n";
            else cout << "NO\n";
        } else if(b1<a2) {
            if(b2>a2) cout << "YES\n";
            else cout << "NO\n";
        } else cout << "NO\n";
    }

    return 0;
}