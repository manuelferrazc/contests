#include <bits/stdc++.h>
#include <cstdlib>

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
    int dias; cin >> dias;

    vector<int[3]> v(dias);
    for(int i=0;i<dias;i++) cin >> v[i][0] >> v[i][1] >> v[i][2];

    vector<int[3]> feliz(dias);
    
    feliz[0][0] = v[0][0];
    feliz[0][1] = v[0][1];
    feliz[0][2] = v[0][2];

    for(int i=1;i<dias;i++) {
        for(int j=0;j<3;j++) {
            feliz[i][j] = max(feliz[i-1][(j+1)%3],feliz[i-1][(j+2)%3]) + v[i][j]; 
        }
    }

    

    cout << max(feliz[dias-1][0],max(feliz[dias-1][1],feliz[dias-1][2])) << '\n';

    return 0;
}