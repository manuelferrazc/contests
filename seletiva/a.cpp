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
    ll custo_inicial,meta,dinheiro, necessario=0;
    cin >> custo_inicial >> dinheiro >> meta;
    for(ll i=1;i<=meta;i++) necessario+=custo_inicial*i;

    if(necessario > dinheiro) cout << necessario-dinheiro << endl;
    else cout << 0 << endl;
    return 0;
}