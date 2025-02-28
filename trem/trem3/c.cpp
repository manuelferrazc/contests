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




int main() { _
    int size; cin >> size;
    string alice, bob; cin >> bob;
    
    int Rs=0, Ls=0;
    alice = bob;

    for(int i=0;i<size;i++) {
        if(bob[i]=='R') {
            Rs++;
        }
        else {
            Ls++;
        }
    }

    int pontos=0;

    for(int i=0;i<size and Rs<Ls-1; i++) {
        if(bob[i]=='R') continue;

        alice[i] = 'R';
        Rs++;
        Ls--;
        pontos++;
    }

    cout << pontos << '\n' << alice << '\n';

    return 0;
}