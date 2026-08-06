#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;


int main() { _
	string ta,td;
	cin >> ta >> td;

	ll p,h;
	cin >> p >> h;
	
	char a = ta[0], d = td[0];
	ll dano;

	if((a=='F' and d=='G') or (a=='G' and d=='W') or (a=='W' and d=='F')) dano = 2*p;
	else dano = p/2;

	ll rem = max(0ll,h-dano);

	if(rem==0) cout << "Nocaute!\n";
	else cout << "Sobraram " << rem << " pontos de vida!\n";

	return 0;
}
