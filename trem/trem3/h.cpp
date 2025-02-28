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
    int testes, n_apt, n_p_andar, andar;
    cin >> testes;

    while(testes) {
        testes--;

        cin >> n_apt >> n_p_andar;

        if(n_apt<=2) {
            cout << 1 << '\n';
            continue;
        }
        andar=2;
        n_apt-=2;
        while(n_apt>n_p_andar) {
            n_apt-=n_p_andar;
            andar++;
        }
        cout << andar << '\n';
    }
    

    return 0;
}