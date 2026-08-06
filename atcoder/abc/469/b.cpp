#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int n;
	string s;
	cin >> n >> s;
	s = 'x'+s+'x';

	int qtd=0;
	for(int i=1;i<=n;i++) 
		if(s[i+1]=='x' and s[i]=='x' and s[i-1]=='x') qtd++;
	cout << qtd << '\n';
    return 0;
}
