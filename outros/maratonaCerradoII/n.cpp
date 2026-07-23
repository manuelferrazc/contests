#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define _ ios_base::sync_with_stdio();cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	string a,f;
	cin >> f >> a;

	string s(5,':');

	int total = stoi(string()+f[0]+f[1])*60+stoi(string()+f[3]+f[4]);
	int agr   = stoi(string()+a[0]+a[1])*60+stoi(string()+a[3]+a[4]);

	int dif = total-agr;

	int horas = dif/60;
	if(horas<10) cout << 0;
	cout << horas << ':';
	dif%=60;
	if(dif<10) cout << 0;
	cout << dif << '\n';
	

	return 0;
}
