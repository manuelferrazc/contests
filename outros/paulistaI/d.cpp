#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n;
	cin >> n;

	for(int i=0;i<n;i++) cout << ' ';
	for(int i=0;i<=n;i++) cout << '_';
	cout << '\n';
	
	for(int i=n-1;i>0;i--) {
		for(int j=0;j<i;j++) cout << ' ';
		cout << '/';
		for(int j=0;j< n+1+2*(n-i-1);j++) cout << ' ';
		cout << '\\';
		cout << '\n';
	}

	cout << '/';
	for(int j=0;j<n;j++) cout << '_';
	for(int j=0;j<2*n-1;j++) cout << ' ';
	cout << '\\';
	for(int j=0;j<=n;j++) cout << '_';
	cout << '\n';

	for(int i=1;i<n;i++) {
		for(int j=0;j<n+i;j++) cout << ' ';
		cout << '\\';
		for(int j=1;j<=n+1+2*(n-i);j++) cout << ' ';
		cout << "/\n";
	}

	for(int j=1;j<=2*n;j++) cout << ' ';
	cout << '\\';
	for(int i=0;i<=n;i++) cout << '_';
	cout << "/\n";


	exit(0);
}
