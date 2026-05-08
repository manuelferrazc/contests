#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main(int argc, char**argv) { _
    srand(atoi(argv[1]));

	int n = 1+rand()%10;
	cout << 1 << ' ' << n << '\n';

	for(int i=0;i<n;i++) cout << 1+rand()%20 << ' ';
	cout << '\n';
	for(int i=0;i<n;i++) cout << 1+rand()%20 << ' ';
	cout << '\n';

    return 0;
}
