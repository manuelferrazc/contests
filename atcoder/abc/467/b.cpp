#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int n;
	cin >> n;

	ll troco = 0;
	ll fds = 0;

	for(int i=0;i<n;i++) {
		int a,b;
		string s;
		cin >> a >> b >> s;

		troco += b-a;
		if(s[0]=='t') fds += b-a;
	}

	cout << troco - fds << '\n';

    return 0;
}
